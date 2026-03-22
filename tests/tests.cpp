#include "stack.h"
#include <cassert>
#include <iostream>

static void test_push_pop_lifo() {
    Stack stack;
    stack_init(&stack, 0);

    assert(stack_is_empty(&stack));
    assert(!stack_is_full(&stack));

    assert(stack_push(&stack, 10));
    assert(stack_push(&stack, 20));
    assert(stack_push(&stack, 30));

    int value = 0;
    assert(stack_peek(&stack, &value));
    assert(value == 30);

    assert(stack_pop(&stack, &value));
    assert(value == 30);
    assert(stack_pop(&stack, &value));
    assert(value == 20);
    assert(stack_pop(&stack, &value));
    assert(value == 10);

    assert(stack_is_empty(&stack));
    stack_destroy(&stack);
}

static void test_underflow() {
    Stack stack;
    stack_init(&stack, 0);

    int value = 123;
    assert(!stack_pop(&stack, &value));
    assert(!stack_peek(&stack, &value));

    stack_destroy(&stack);
}

static void test_overflow_com_max() {
    Stack stack;
    stack_init(&stack, 2);

    assert(stack_push(&stack, 1));
    assert(stack_push(&stack, 2));
    assert(stack_is_full(&stack));
    assert(!stack_push(&stack, 3));

    int value = 0;
    assert(stack_pop(&stack, &value));
    assert(value == 2);
    assert(!stack_is_full(&stack));

    stack_destroy(&stack);
}

int main() {
    test_push_pop_lifo();
    test_underflow();
    test_overflow_com_max();

    std::cout << "Todos os testes passaram.\n";
    return 0;
}
