class MergeSort {
public:
    void sort(int* arr, int length); // Метод для начала сортировки
private:
    void merge(int* arr, int low, int mid, int high); // Метод для слияния подмассивов
    void mergeSort(int* arr, int low, int high); // Рекурсивный метод сортировки
};

void printArray(int* arr, int length); // Функция для вывода массива
