from typing import Protocol

from modelos import Alarme, EventoOperacional


class ObservadorEvento(Protocol):
    def notificar(self, evento: EventoOperacional) -> None:
        ...


class GerenciadorAlarmes:
    def __init__(self) -> None:
        self._alarmes: list[Alarme] = []

    def notificar(self, evento: EventoOperacional) -> None:
        if evento.severidade in {"media", "alta", "critica"}:
            self._alarmes.append(Alarme(
                timestamp=evento.timestamp,
                origem=evento.origem,
                tipo=evento.tipo,
                mensagem=evento.mensagem,
                severidade=evento.severidade,
            ))

    def listar(self) -> list[Alarme]:
        return self._alarmes


class LoggerConsole:
    def notificar(self, evento: EventoOperacional) -> None:
        print(f"[EVENTO] {evento.origem} - {evento.tipo} - {evento.mensagem}")


class RepositorioEventosMemoria:
    def __init__(self) -> None:
        self._eventos: list[EventoOperacional] = []

    def notificar(self, evento: EventoOperacional) -> None:
        self._eventos.append(evento)

    def listar(self) -> list[EventoOperacional]:
        return self._eventos
