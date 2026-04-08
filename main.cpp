#include "include/stack.h"
#include <iostream>
#include <string>

using namespace std;

bool valida_expressao(string expressao){
    Stack<char> stack;
    stack.init(0);

    for(char c : expressao){

        if(c == '(' || c == '[' || c == '{'){
            stack.push(c);
        }
        else if(c == ')' || c == ']' || c == '}'){
            char topo;

            if(!stack.pop(&topo)){
                stack.destroy();
                return false;
            }

            if( (c == ')' && topo != '(') ||
                (c == ']' && topo != '[') ||
                (c == '}' && topo != '{') ){
                stack.destroy();
                return false;
            }
        }
    }

    char resto;
    bool vazio = !stack.pop(&resto);

    stack.destroy();
    return vazio;
}

int main() {
    string expressao;

    cout << "Digite uma expressao: ";
    getline(cin, expressao);

    if(valida_expressao(expressao)){
        cout << "Expressao VALIDA " << endl;
    } else {
        cout << "Expressao INVALIDA " << endl;
    }

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