#include "stack.h"
#include <cassert>
#include <iostream>

static void test_push_pop_lifo() {
    Stack<int> stack;
    stack.init(0);

    assert(stack.empty());
    assert(!stack.is_full());

    assert(stack.push(10));
    assert(stack.push(20));
    assert(stack.push(30));

    int value = 0;
    assert(stack.peek(&value));
    assert(value == 30);

    assert(stack.pop(&value));
    assert(value == 30);
    assert(stack.pop(&value));
    assert(value == 20);
    assert(stack.pop(&value));
    assert(value == 10);

    assert(stack.empty());
    stack.destroy();
}

static void test_underflow() {
    Stack<int> stack;
    stack.init(0);

    int value = 123;
    assert(!stack.pop(&value));
    assert(!stack.peek(&value));

    stack.destroy();
}

static void test_overflow_com_max() {
    Stack<int> stack;
    stack.init(2);

    assert(stack.push(1));
    assert(stack.push(2));
    assert(stack.is_full());
    assert(!stack.push(3));

    int value = 0;
    assert(stack.pop(&value));
    assert(value == 2);
    assert(!stack.is_full());

    stack.destroy();
}

static void test_size() {
    Stack<int> stack;
    stack.init(0);

    assert(stack.size() == 0);

    assert(stack.push(1));
    assert(stack.size() == 1);
    assert(stack.push(2));
    assert(stack.size() == 2);

    int value = 0;
    assert(stack.pop(&value));
    assert(stack.size() == 1);
    assert(stack.pop(&value));
    assert(stack.size() == 0);

    stack.destroy();
}

int main() {
    test_push_pop_lifo();
    test_underflow();
    test_overflow_com_max();
    test_size();

    std::cout << "Todos os testes passaram.\n";
    return 0;
}
