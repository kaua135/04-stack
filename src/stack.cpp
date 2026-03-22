#include "stack.h"

// Inicializa a pilha com tamanho maximo (0 = sem limite)
void stack_init(Stack* stack, std::size_t max_size) {
    stack->top = nullptr;
    stack->size = 0;
    stack->max_size = max_size;
}

// Libera todos os nos alocados
void stack_destroy(Stack* stack) {
    Node* current = stack->top;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    stack->top = nullptr;
    stack->size = 0;
}

bool stack_is_empty(const Stack* stack) {
    return stack->size == 0;
}

bool stack_is_full(const Stack* stack) {
    if (stack->max_size == 0) {
        return false;
    }
    return stack->size >= stack->max_size;
}

bool stack_push(Stack* stack, int value) {
    if (stack_is_full(stack)) {
        return false;
    }

    Node* node = new Node{value, stack->top};
    stack->top = node;
    stack->size += 1;
    return true;
}

bool stack_pop(Stack* stack, int* out_value) {
    if (stack_is_empty(stack)) {
        return false;
    }

    Node* node = stack->top;
    if (out_value != nullptr) {
        *out_value = node->value;
    }
    stack->top = node->next;
    delete node;
    stack->size -= 1;
    return true;
}

bool stack_peek(const Stack* stack, int* out_value) {
    if (stack_is_empty(stack)) {
        return false;
    }
    if (out_value != nullptr) {
        *out_value = stack->top->value;
    }
    return true;
}
