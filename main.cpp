#include "include/stack.h"
#include <iostream>
#include <string>

using namespace std;

// ---------- PALINDROMO ----------
bool valida_palindromo(string palavra) {
    Stack<char> stack;
    stack.init(0);

    for (int i = 0; i < palavra.length(); i++) {
        stack.push(palavra[i]);
    }

    for (int i = 0; i < palavra.length(); i++) {
        char letra;
        stack.pop(&letra);

        if (palavra[i] != letra) {
            stack.destroy();
            return false;
        }
    }

    stack.destroy();
    return true;
}

// ---------- EXPRESSAO ----------
bool valida_expressao(string expressao) {
    Stack<char> stack;
    stack.init(0);

    for (int i = 0; i < expressao.length(); i++) {
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            char topo;

            if (!stack.pop(&topo)) {
                stack.destroy();
                return false;
            }

            if ((c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{')) {
                stack.destroy();
                return false;
            }
        }
    }

    bool correta = stack.empty();

    stack.destroy();
    return correta;
}

// ---------- DECIMAL PARA BINARIO ----------
void decimal_para_binario(int numero) {
    Stack<int> stack;
    stack.init(0);

    if (numero == 0) {
        cout << "Binario: 0" << endl;
        return;
    }

    while (numero > 0) {
        stack.push(numero % 2);
        numero = numero / 2;
    }

    int bit;

    cout << "Binario: ";

    while (stack.pop(&bit)) {
        cout << bit;
    }

    cout << endl;

    stack.destroy();
}

int main() {

    // ---------- PALINDROMO ----------
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (valida_palindromo(palavra)) {
        cout << "A palavra e um palindromo" << endl;
    } else {
        cout << "A palavra nao e um palindromo" << endl;
    }

    cin.ignore();

    // ---------- EXPRESSAO ----------
    string expressao;

    cout << "\nDigite uma expressao matematica: ";
    getline(cin, expressao);

    if (valida_expressao(expressao)) {
        cout << "Expressao CORRETA" << endl;
    } else {
        cout << "Expressao INCORRETA" << endl;
    }

    // ---------- DECIMAL PARA BINARIO ----------
    int numero;

    cout << "\nDigite um numero decimal: ";
    cin >> numero;

    decimal_para_binario(numero);

    // ---------- MAIN ORIGINAL ----------
    Stack<int> stack;
    stack.init(0);

    cout << "\nEmpilhando: 5, 10, 15\n";
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

    return 0;
}