#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>
#include <condition_variable>
#include <cstring>
#include <cstdlib>
#include <netinet/in.h>
#include <unistd.h>
#include <sstream>

#define PORT 8081

std::mutex mtx;
std::condition_variable cv;
bool found = false;

void handleWorker(int socket, int workerId, const std::string &charset, int maxLength) {
    for (int length = 1; length <= maxLength; ++length) {
        long long totalCombinations = std::pow(charset.size(), length);
        long long range = totalCombinations / 5; // 5 воркеров
        long long remainder = totalCombinations % 5;

        long long startIdx = workerId * range + std::min((long long)workerId, remainder);
        long long endIdx = startIdx + range - 1 + (workerId < remainder ? 1 : 0);

        std::ostringstream task;
        task << length << " " << startIdx << " " << endIdx << " " << charset;

        send(socket, task.str().c_str(), task.str().size(), 0);

        char buffer[1024] = {0};
        int valread = read(socket, buffer, 1024);
        if (valread > 0) {
            std::string result(buffer);
            if (result.find("FOUND:") == 0) {
                std::cout << "Password found by worker " << workerId << ": " << result.substr(6) << std::endl;

                {
                    std::lock_guard<std::mutex> lock(mtx);
                    found = true;
                }

                cv.notify_all();

                close(socket);
                return;
            }
        }

        if (found) break;
    }

    close(socket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int maxLength = 6;

    std::vector<std::thread> workers;
    for (int i = 0; i < 5; ++i) { // 5 воркеров
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        workers.emplace_back(handleWorker, new_socket, i, charset, maxLength);
    }

    for (auto &worker : workers) {
        worker.join();
    }

    close(server_fd);
    return 0;
}
