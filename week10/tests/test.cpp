// tests/test.cpp
#include <gtest/gtest.h>
#include "../include/Stack.hpp"

using namespace std;

TEST(StackTest, PushPopTest) {
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, TopTest) {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);

    EXPECT_EQ(stack.top(), 20);
    stack.pop();
    EXPECT_EQ(stack.top(), 10);
}

TEST(StackTest, EmptyStackPop) {
    Stack<int> stack;

    EXPECT_THROW(stack.pop(), out_of_range);
}

TEST(StackTest, EmptyStackTop) {
    Stack<int> stack;

    EXPECT_THROW(stack.top(), out_of_range);
}

TEST(StackTest, SizeTest) {
    Stack<int> stack;

    EXPECT_EQ(stack.size(), 0);
    stack.push(1);
    stack.push(2);
    EXPECT_EQ(stack.size(), 2);
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
}
