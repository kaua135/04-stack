#include "stack.h"
#include <iostream>

int main() {
    Stack stack;
    stack_init(&stack, 0);

    std::cout << "Empilhando: 5, 10, 15\n";
    stack_push(&stack, 5);
    stack_push(&stack, 10);
    stack_push(&stack, 15);

    int value = 0;
    if (stack_peek(&stack, &value)) {
        std::cout << "Topo atual: " << value << "\n";
    }

    std::cout << "Desempilhando...\n";
    while (stack_pop(&stack, &value)) {
        std::cout << "Removeu: " << value << "\n";
    }

    if (!stack_pop(&stack, &value)) {
        std::cout << "Underflow: pilha vazia.\n";
    }

    stack_destroy(&stack);
    return 0;
}
