from dataclasses import dataclass
from enum import Enum


class TipoComando(Enum):
    NENHUM = "NENHUM"
    LIGAR_BOMBA = "LIGAR_BOMBA"
    DESLIGAR_BOMBA = "DESLIGAR_BOMBA"
    BLOQUEAR_PARTIDA = "BLOQUEAR_PARTIDA"


@dataclass
class Leitura:
    timestamp: str
    tag: str
    valor: float
    unidade: str
    status: str
