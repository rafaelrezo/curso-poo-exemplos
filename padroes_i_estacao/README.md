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
    tests/
      test_controle.cpp
  supervisor_python/
    app_demo.py
    modelos.py
    repositorios.py
    requirements-dev.txt
    validacao.py
    tests/
      test_repositorios.py
      test_validacao.py
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

## Como executar os testes

### Testes C++

```bash
mkdir -p dispositivo_cpp/build
g++ -std=c++17 -Wall -Wextra -pedantic \
  -I dispositivo_cpp/include \
  dispositivo_cpp/tests/test_controle.cpp \
  -o dispositivo_cpp/build/test_controle

./dispositivo_cpp/build/test_controle
```

### Testes Python

```bash
cd supervisor_python
python3 -m pip install -r requirements-dev.txt
python3 -m pytest -q
```

## Leitura recomendada

- `estrategia_controle.hpp`: regras de controle (`Strategy`).
- `comando.hpp`: ações de atuação (`Command`).
- `repositorios.py`: acesso a dados (`Repository`).
- `validacao.py`: validação do contrato JSON.
- `tests/`: exemplos pequenos de testes automatizados.
- `main.cpp` e `app_demo.py`: fluxo completo usando as peças.
- `sem_padroes/`: contraexemplos para comparar com a versão organizada.
