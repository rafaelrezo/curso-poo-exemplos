# Referência opcional - Testes e CI da Estação de Bombeamento

Este repositório de referência mostra uma versão pequena, executável e testável da estação de bombeamento usada na parte 2 do curso.

O objetivo não é entregar o projeto final pronto. O objetivo é mostrar uma base realista para:

- organizar código C++ e Python em pastas separadas;
- escrever testes unitários, de contrato e de integração;
- executar os testes localmente;
- configurar GitHub Actions para rodar os mesmos testes no pull request.

Link público, quando publicado:

<https://github.com/rafaelrezo/curso-poo-exemplos/tree/main/testes_ci_estacao>

---

## Estrutura

```text
testes_ci_estacao/
  .github/
    workflows/
      testes.yml
  dados/
    leituras_exemplo.jsonl
  dispositivo_cpp/
    include/
      bomba.hpp
      comando.hpp
      controlador_estacao.hpp
      estrategia_controle.hpp
      telemetria.hpp
      tipo_comando.hpp
    src/
      main.cpp
    tests/
      test_controlador.cpp
  supervisor_python/
    estacao/
      alarmes.py
      ingestao.py
      modelos.py
      repositorios.py
      validacao.py
    tests/
      test_alarmes.py
      test_ingestao.py
      test_repositorios.py
      test_validacao.py
    requirements-dev.txt
  README.md
```

---

## Como executar o controlador C++

```bash
cd dispositivo_cpp
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude src/main.cpp -o build/estacao
./build/estacao
```

Saída esperada:

```text
Estrategia: ControleNormal
Decisao: LIGAR_BOMBA
Comando executado: LIGAR_BOMBA
{"tag":"LT-101","valor":25.00,"unidade":"%","timestamp":"2026-06-09T10:30:00-03:00","status":"operando"}
```

---

## Como executar os testes C++

```bash
cd dispositivo_cpp
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic -Iinclude tests/test_controlador.cpp -o build/test_controlador
./build/test_controlador
```

Se o programa terminar sem mensagens, os `asserts` passaram.

---

## Como executar os testes Python

```bash
cd supervisor_python
python3 -m pip install -r requirements-dev.txt
python3 -m pytest -q
```

Os testes Python cobrem:

- contrato JSON;
- geração de alarmes;
- Repository em memória;
- Repository SQLite com banco temporário;
- ingestão de arquivo JSON Lines.

---

## Como o CI funciona

O arquivo `.github/workflows/testes.yml` possui dois jobs:

- `cpp`: compila e executa os testes do controlador C++;
- `python`: instala dependências e executa `pytest`.

O workflow roda em:

- `push`;
- `pull_request`.

Essa configuração mostra a ideia central de integração contínua: o mesmo conjunto mínimo de comandos usados localmente passa a ser executado automaticamente no GitHub.

Se este exemplo for publicado dentro do repositório `curso-poo-exemplos`, o workflow executável pela aba **Actions** fica na raiz do repositório:

```text
.github/workflows/testes-ci-estacao.yml
```

O arquivo dentro desta pasta serve como referência para quem quiser copiar `testes_ci_estacao` para um repositório próprio.

---

## Como usar no curso

Use este repositório como visualização opcional quando quiser comparar sua solução com uma referência pequena e executável.

Não copie o projeto final a partir daqui. A entrega da dupla deve ter assinatura operacional própria, sensores próprios, regras próprias e defesa técnica própria.
