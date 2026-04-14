#include "include/stack.h"
#include <iostream>
#include <string>

using namespace std;

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

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (valida_palindromo(palavra)) {
        cout << "E palindromo\n";
    } else {
        cout << "Nao e palindromo\n";
    }

    return 0;
}