#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include "node.h"

// Estrutura principal da pilha
struct Stack {
    Node* top;
    std::size_t size;
    std::size_t max_size; // 0 significa sem limite
};

// Inicializa a pilha
void stack_init(Stack* stack, std::size_t max_size);

// Libera todos os nos da pilha
void stack_destroy(Stack* stack);

// Verifica se a pilha esta vazia
bool stack_is_empty(const Stack* stack);

// Verifica se a pilha esta cheia
bool stack_is_full(const Stack* stack);

// Insere elemento no topo
bool stack_push(Stack* stack, int value);

// Remove elemento do topo e salva em out_value
bool stack_pop(Stack* stack, int* out_value);

// Retorna o elemento do topo sem remover
bool stack_peek(const Stack* stack, int* out_value);

#endif
