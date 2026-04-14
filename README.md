# Pilha (Stack) em C++

Exercício acadêmico de implementação de uma Pilha (LIFO) com alocação dinâmica de memória, sem uso de `std::stack`.

## Estrutura do Projeto

```
/
├── .vscode/         # Tarefas de build e debug (VSCode)
├── include/         # Headers (.h)
├── src/             # (vazio) implementacao em headers
├── tests/           # Testes automatizados
├── build/           # Binarios gerados
└── main.cpp         # Ponto de entrada para demonstração
```

## Requisitos

- Compilador: `g++` (C++17)
- (Opcional) VSCode + GDB para debug

## Compilacao e Execucao

em caso de erro qe no final do codigo esta dando -1 faça da seguinte forma:
abra um novo terminal
depois coloque esse comando: g++ main.cpp -o programa
de enter e logo em seguida esse comando .\programa.exe
o codigo ira rodar normalmente como deveria.

### Manual (terminal)

```bash
# Compilar e executar o programa principal
mkdir -p build
g++ main.cpp -Iinclude -o build/main
./build/main

# Compilar e executar os testes
g++ tests/tests.cpp -Iinclude -o build/tests
./build/tests
```

### Via VSCode

- **Build project**: `Ctrl+Shift+B`
- **Build tests**: `Ctrl+Shift+P` → "Tasks: Run Task" → "build tests"
- **Debug**: `F5` (usa GDB)
