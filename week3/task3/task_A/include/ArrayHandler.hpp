class ArrayHandler {
private:
    double* data_array; // Указатель на массив
    int size;

public:
    ArrayHandler(int n); // Конструктор
    ~ArrayHandler(); // Деструктор

    void inputArray(); // Метод для ввода массива
    void bubbleSort(); // Метод для сортировки массива
    int countMaxOccurrences(); // Метод для подсчета максимальных значений
};

