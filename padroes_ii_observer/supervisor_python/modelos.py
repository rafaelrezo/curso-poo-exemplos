from dataclasses import dataclass


@dataclass
class Leitura:
    timestamp: str
    tag: str
    tipo: str
    valor: float | None
    unidade: str
    status: str


@dataclass
class EventoOperacional:
    timestamp: str
    origem: str
    tipo: str
    mensagem: str
    severidade: str


@dataclass
class Alarme:
    timestamp: str
    origem: str
    tipo: str
    mensagem: str
    severidade: str
