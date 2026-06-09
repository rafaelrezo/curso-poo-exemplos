# Exemplo de apoio - Padrões II: Observer

Este exemplo mostra o padrão `Observer` organizado em arquivos pequenos.

O objetivo é mostrar como a estação publica eventos sem conhecer os detalhes de quem vai reagir.

## Estrutura

```text
padroes_ii_observer/
  sem_observer/
    dispositivo_cpp/
      main.cpp
  dispositivo_cpp/
    include/
      estacao_bombeamento.hpp
      evento_operacional.hpp
      gerenciador_alarmes.hpp
      logger_console.hpp
      observador_evento.hpp
      registrador_eventos.hpp
    src/
      main.cpp
```

## Como executar

### Contraexemplo sem Observer

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
  sem_observer/dispositivo_cpp/main.cpp \
  -o /tmp/padroes_ii_sem_observer_cpp

/tmp/padroes_ii_sem_observer_cpp
```

### Exemplo com Observer

```bash
g++ -std=c++17 -Wall -Wextra -pedantic \
  -I dispositivo_cpp/include \
  dispositivo_cpp/src/main.cpp \
  -o /tmp/padroes_ii_observer_cpp

/tmp/padroes_ii_observer_cpp
```

## Leitura recomendada

- `evento_operacional.hpp`: dado publicado pela estação.
- `observador_evento.hpp`: interface comum dos observadores.
- `gerenciador_alarmes.hpp`: observador que guarda alarmes.
- `logger_console.hpp`: observador que imprime eventos.
- `registrador_eventos.hpp`: observador que simula persistência.
- `estacao_bombeamento.hpp`: sujeito observado.
- `sem_observer/`: contraexemplo para comparar com a versão organizada.
