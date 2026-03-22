# AGENTS.md

## Descrição do Projeto

Exercício acadêmico de implementação de **Pilha (Stack)** em C++.

A pilha é uma estrutura LIFO (Last In First Out) com alocação encadeada (dinâmica).
As operações principais são:
- `push` (empilhar): insere elemento no topo
- `pop` (desempilhar): remove elemento do topo
- Tratamento de `overflow` (pilha cheia) e `underflow` (pilha vazia)

## Convenções de Código

- Linguagem: **C++17**
- Nomeação: `snake_case` para funções e variáveis, `PascalCase` para structs
- Um header por struct em `/include`
- Sem uso de `std::stack` ou outras estruturas prontas da STL — a pilha deve ser implementada do zero
- Comentários em **português**

## Estrutura do Projeto
/
├── .vscode/
│   ├── tasks.json      # Tarefas de build (compilar projeto e testes)
│   └── launch.json     # Configuração de debug com GDB
├── include/            # Headers (.h) — declarações da estrutura e funções da pilha
├── src/                # Implementação (.cpp) — lógica das operações da pilha
├── tests/              # Testes automatizados
└── main.cpp            # Ponto de entrada para demonstração manual

## Compilação e Execução

### Manual (terminal)

```bash
# Compilar e executar o programa principal
g++ main.cpp src/stack.cpp -Iinclude -o main
./main

# Compilar e executar os testes
g++ tests/tests.cpp src/stack.cpp -Iinclude -o tests_bin
./tests_bin
```

### Via VSCode

- **Build project**: `Ctrl+Shift+B` (tarefa padrão definida em `.vscode/tasks.json`)
- **Build tests**: abrir a paleta de comandos (`Ctrl+Shift+P`) → "Tasks: Run Task" → "build tests"
- **Debug**: `F5` (usa a configuração definida em `.vscode/launch.json`)

> Sempre rode os testes após qualquer alteração e certifique-se que todos passam antes de concluir.

## Configuração do VSCode

### `.vscode/tasks.json`

Define duas tarefas de build, ambas com flag `-g` para suporte a debug com GDB.

```jsonc
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build project",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/main.cpp",
                "${workspaceFolder}/src/stack.cpp",
                "-I${workspaceFolder}/include",
                "-o",
                "${workspaceFolder}/main"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"],
            "detail": "Tarefa de compilação manual para debug com GDB."
        },
        {
            "label": "build tests",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",
                "${workspaceFolder}/tests/tests.cpp",
                "${workspaceFolder}/src/stack.cpp",
                "-I${workspaceFolder}/include",
                "-o",
                "${workspaceFolder}/tests/tests"
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": ["$gcc"],
            "detail": "Tarefa de compilação para os testes."
        }
    ]
}
```

### `.vscode/launch.json`

Configura o GDB para depurar o executável principal. Executa o build automaticamente antes de iniciar o debug via `preLaunchTask`.

```jsonc
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug project",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/main",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "preLaunchTask": "build project",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        },
        {
            "name": "Debug tests",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/tests/tests",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "/usr/bin/gdb",
            "preLaunchTask": "build tests",
            "setupCommands": [
                {
                    "description": "Habilitar pretty-printing para GDB",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

> Sempre rode os testes após qualquer alteração e certifique-se que todos passam antes de concluir.

## Ferramentas

- Compilador: `g++` (GCC/G++)
- Debugger: `gdb`
- Editor recomendado: Visual Studio Code