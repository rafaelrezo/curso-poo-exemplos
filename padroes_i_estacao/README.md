# Exemplo de apoio - Padrões I: Strategy, Command e Repository

Este exemplo mostra a mesma estação organizada em arquivos pequenos.

O objetivo não é criar uma arquitetura grande. O objetivo é mostrar que separar responsabilidades deixa o projeto mais fácil de ler, testar e alterar.

## Estrutura

```text
padroes_i_estacao/
  sem_padroes/
    dispositivo_cpp/
      main.cpp
    supervisor_python/
      app_sem_repository.py
  dispositivo_cpp/
    include/
      bomba.hpp
      comando.hpp
      controlador_estacao.hpp
      estrategia_controle.hpp
      tipo_comando.hpp
    src/
      main.cpp
  supervisor_python/
    app_demo.py
    modelos.py
    repositorios.py
```

## Como executar o C++

### Contraexemplo sem padrões

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
  sem_padroes/dispositivo_cpp/main.cpp \
  -o /tmp/padroes_i_sem_padroes_cpp

/tmp/padroes_i_sem_padroes_cpp
```

### Exemplo com padrões

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
  -I dispositivo_cpp/include \
  dispositivo_cpp/src/main.cpp \
  -o /tmp/padroes_i_estacao_cpp

/tmp/padroes_i_estacao_cpp
```

## Como executar o Python

### Contraexemplo sem Repository

```bash
python3 sem_padroes/supervisor_python/app_sem_repository.py
```

### Exemplo com Repository

```bash
python3 supervisor_python/app_demo.py
```

## Leitura recomendada

- `estrategia_controle.hpp`: regras de controle (`Strategy`).
- `comando.hpp`: ações de atuação (`Command`).
- `repositorios.py`: acesso a dados (`Repository`).
- `main.cpp` e `app_demo.py`: fluxo completo usando as peças.
- `sem_padroes/`: contraexemplos para comparar com a versão organizada.
