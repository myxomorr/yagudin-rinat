#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include <vector>

// Интерфейс стека
template <typename T>
class StackImpl {
public:
    virtual ~StackImpl() = default;

    // Чисто виртуальные функции
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual size_t size() const = 0;
};

// Конкретная реализация стека
template <typename T>
class Stack : public StackImpl<T> {
public:
    Stack();
    void push(const T& value) override;
    T pop() override;
    T top() const override;
    bool isEmpty() const override;
    size_t size() const override;

private:
    std::vector<T> data;
    size_t current_size;
};

#endif
