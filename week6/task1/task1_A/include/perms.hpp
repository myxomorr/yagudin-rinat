#include <list>

// Объявление функции для генерации перестановок
void perms(std::list<int> &nums, std::list<int>::iterator start, std::list<std::list<int>> &result);

// Объявление функции для получения всех перестановок
std::list<std::list<int>> getPermutations(std::list<int> nums);