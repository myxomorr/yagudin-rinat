#include "../include/searchFiles.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

vector<string> searchFilesByName(const string& directory, const string& filename) {
    vector<string> foundFiles;

    for (const auto& entry : filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().filename() == filename) {
            foundFiles.push_back(entry.path().string());
        }
    }

    return foundFiles;
}

vector<string> searchFilesByContent(const string& directory, const string& content) {
    vector<string> foundFiles;

    for (const auto& entry : filesystem::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            ifstream file(entry.path());
            string line;
            while (getline(file, line)) {
                if (line.find(content) != string::npos) {
                    foundFiles.push_back(entry.path().string());
                    break; // Если нашли содержимое, выходим из цикла
                }
            }
        }
    }

    return foundFiles;
}
