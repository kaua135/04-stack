#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

bool valida_expressao(string expressao) {
    Stack<char> pilha;
    pilha.init(0);

    for (int i = 0; i < expressao.length(); ++i) {
        char simbolo = expressao[i];

        switch (simbolo) {
            case '(':
            case '[':
            case '{':
                if (!pilha.push(simbolo)) {
                    pilha.destroy();
                    return false;
                }
                break;

            case ')': {
                char topo;
                if (!pilha.peek(&topo) || topo != '(') {
                    pilha.destroy();
                    return false;
                }
                pilha.pop(nullptr);
                break;
            }
            case ']': {
                char topo;
                if (!pilha.peek(&topo) || topo != '[') {
                    pilha.destroy();
                    return false;
                }
                pilha.pop(nullptr);
                break;
            }
            case '}': {
                char topo;
                if (!pilha.peek(&topo) || topo != '{') {
                    pilha.destroy();
                    return false;
                }
                pilha.pop(nullptr);
                break;
            }
            default:
                break;
        }
    }

    bool resultado = pilha.empty();
    pilha.destroy();
    return resultado;
}

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

    cout << "Empilhando: 5, 10, 15\n";
    stack.push(5);
    stack.push(10);
    stack.push(15);

    int value = 0;
    if (stack.peek(&value)) {
        cout << "Topo atual: " << value << "\n";
    }

    cout << "Desempilhando...\n";
    while (stack.pop(&value)) {
        cout << "Removeu: " << value << "\n";
    }

    if (!stack.pop(&value)) {
        cout << "Underflow: pilha vazia.\n";
    }

    stack.destroy();

    if (detecta_palindromo("arara")) {
        cout << "É palíndromo" << endl;
    } else {
        cout << "Não é palíndromo" << endl;
    }

    string exemplo1 = "([12 + (5*9)] + [24 - 5])";
    string exemplo2 = "([)]";

    cout << "Exemplo 1: " << exemplo1 << "\": "
              << (valida_expressao(exemplo1) ? "bem formada" : "mal formada") << endl;
    cout << "Exemplo 2: " << exemplo2 << "\": "
              << (valida_expressao(exemplo2) ? "bem formada" : "mal formada") << endl;

    return 0;
}
