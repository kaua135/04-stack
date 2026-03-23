#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

bool detecta_palindromo(string original) {
    // string original = "arara";
    Stack<char> stack;
    stack.init(0);

    for (int i = 0; i < original.length(); i++) {
        cout << original[i] << endl;
        stack.push(original[i]);
    }

    string invertida;

    for (int i = 0; i < original.length(); i++) {
        char letra_invertida;
        stack.pop(&letra_invertida);
        invertida += letra_invertida;
    }

    cout << original << endl;
    cout << invertida << endl;

    return original.compare(invertida) == 0;
}

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

    if (detecta_palindromo("arara")) {
        cout << "É palíndromo" << endl;
    } else {
        cout << "Não é palíndromo" << endl;
    }

    return 0;
}
