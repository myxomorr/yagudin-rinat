#include <iostream>
#include "../include/searchFiles.hpp"

int main() {
    std::string directory;
    std::string filename;
    std::string content;

    std::cout << "Введите путь к директории: ";
    std::getline(std::cin, directory);

    std::cout << "Введите имя файла для поиска: ";
    std::getline(std::cin, filename);
    
    std::vector<std::string> filesByName = searchFilesByName(directory, filename);
    if (!filesByName.empty()) {
        std::cout << "Найденные файлы по имени:\n";
        for (const auto& file : filesByName) {
            std::cout << file << std::endl;
        }
    } else {
        std::cout << "Файлы с именем '" << filename << "' не найдены.\n";
    }

    std::cout << "Введите содержимое для поиска в текстовых файлах: ";
    std::getline(std::cin, content);

    std::vector<std::string> filesByContent = searchFilesByContent(directory, content);
    if (!filesByContent.empty()) {
        std::cout << "Найденные файлы по содержимому:\n";
        for (const auto& file : filesByContent) {
            std::cout << file << std::endl;
        }
    } else {
        std::cout << "Файлы с содержимым '" << content << "' не найдены.\n";
    }

    return 0;
}
