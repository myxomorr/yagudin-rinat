#include "../include/Stack.hpp"

// Конструктор стека
template <typename T>
Stack<T>::Stack() : current_size(0) {}

// Метод push
template <typename T>
void Stack<T>::push(const T& value) {
    data.push_back(value);
    current_size++;
}

// Метод pop
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T value = data.back();
    data.pop_back();
    current_size--;
    return value;
}

// Метод top
template <typename T>
T Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

// Метод isEmpty
template <typename T>
bool Stack<T>::isEmpty() const {
    return current_size == 0;
}

// Метод size
template <typename T>
size_t Stack<T>::size() const {
    return current_size;
}

// Инстанцирование шаблонов
template class Stack<int>;
template class Stack<double>;
template class Stack<std::string>;
