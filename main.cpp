#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Stack<int> stack;
    stack.init(0);

    std::cout << "Empilhando: 5, 10, 15\n";
    stack.push(5);
    stack.push(10);
    stack.push(15);

    int value = 0;
    if (stack.peek(&value)) {
        std::cout << "Topo atual: " << value << "\n";
    }

    std::cout << "Desempilhando...\n";
    while (stack.pop(&value)) {
        std::cout << "Removeu: " << value << "\n";
    }

    if (!stack.pop(&value)) {
        std::cout << "Underflow: pilha vazia.\n";
    }

    stack.destroy();

    return 0;
}
