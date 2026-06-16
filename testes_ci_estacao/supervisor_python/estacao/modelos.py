from dataclasses import dataclass


@dataclass(frozen=True)
class Leitura:
    timestamp: str
    tag: str
    valor: float
    unidade: str
    status: str


@dataclass(frozen=True)
class Alarme:
    origem: str
    alarme: str
    severidade: str
    timestamp: str

