#include <iostream>
#include <cstring>
#include <vector>
#include <unistd.h>
#include <openssl/md5.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sstream>
#include <cmath>

#define PORT 8081

const std::string targetHash = "8139bfeb4b17207735b4324a38ca2b10";

std::string md5Hash(const std::string &str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *)str.c_str(), str.size(), digest);

    char mdString[33];
    for (int i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        snprintf(&mdString[i * 2], 3, "%02x", digest[i]);
    }
    return std::string(mdString);
}

void generateCombinations(int length, long long startIdx, long long endIdx, const std::string &charset, const std::string &targetHash, int socket) {
    long long charsetSize = charset.size();

    for (long long index = startIdx; index <= endIdx; ++index) {
        std::string combination;
        long long tempIndex = index;

        for (int i = 0; i < length; ++i) {
            combination = charset[tempIndex % charsetSize] + combination;
            tempIndex /= charsetSize;
        }

        std::string hash = md5Hash(combination);
        if (hash == targetHash) {
            std::string result = "FOUND:" + combination;
            send(socket, result.c_str(), result.size(), 0);
            return;
        }
    }

    std::string doneMessage = "DONE";
    send(socket, doneMessage.c_str(), doneMessage.size(), 0);
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    char task_buffer[1024] = {0};
    while (true) {
        int valread = read(sock, task_buffer, 1024);

        if (valread <= 0) {
            std::cout << "Worker lost connection." << std::endl;
            break;
        }

        std::istringstream taskStream(task_buffer);
        int length;
        long long startIdx, endIdx;
        std::string charset;

        taskStream >> length >> startIdx >> endIdx >> charset;

        generateCombinations(length, startIdx, endIdx, charset, targetHash, sock);

        if (std::string(task_buffer).find("STOP") != std::string::npos) {
            std::cout << "Worker stopping." << std::endl;
            break;
        }
    }

    close(sock);
    return 0;
}
