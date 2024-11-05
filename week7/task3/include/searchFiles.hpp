#include <string>
#include <vector>

// Функция для поиска файлов по названию
std::vector<std::string> searchFilesByName(const std::string& directory, const std::string& filename);

// Функция для поиска текстовых файлов по содержимому
std::vector<std::string> searchFilesByContent(const std::string& directory, const std::string& content);