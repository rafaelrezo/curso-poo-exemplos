import sqlite3
from typing import Protocol

from modelos import Leitura


class RepositorioLeituras(Protocol):
    def salvar(self, leitura: Leitura) -> None:
        ...

    def listar_todas(self) -> list[Leitura]:
        ...


class RepositorioLeiturasMemoria:
    def __init__(self) -> None:
        self._leituras: list[Leitura] = []

    def salvar(self, leitura: Leitura) -> None:
        self._leituras.append(leitura)

    def listar_todas(self) -> list[Leitura]:
        return self._leituras


class RepositorioLeiturasSqlite:
    def __init__(self, caminho_banco: str) -> None:
        self._caminho_banco = caminho_banco

    def inicializar(self) -> None:
        with sqlite3.connect(self._caminho_banco) as conexao:
            conexao.execute(
                """
                CREATE TABLE IF NOT EXISTS leituras (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    timestamp TEXT NOT NULL,
                    tag TEXT NOT NULL,
                    valor REAL NOT NULL,
                    unidade TEXT NOT NULL,
                    status TEXT NOT NULL
                )
                """
            )

    def salvar(self, leitura: Leitura) -> None:
        with sqlite3.connect(self._caminho_banco) as conexao:
            conexao.execute(
                """
                INSERT INTO leituras (timestamp, tag, valor, unidade, status)
                VALUES (?, ?, ?, ?, ?)
                """,
                (
                    leitura.timestamp,
                    leitura.tag,
                    leitura.valor,
                    leitura.unidade,
                    leitura.status,
                ),
            )

    def listar_todas(self) -> list[Leitura]:
        with sqlite3.connect(self._caminho_banco) as conexao:
            cursor = conexao.execute(
                "SELECT timestamp, tag, valor, unidade, status FROM leituras"
            )
            return [
                Leitura(
                    timestamp=linha[0],
                    tag=linha[1],
                    valor=linha[2],
                    unidade=linha[3],
                    status=linha[4],
                )
                for linha in cursor.fetchall()
            ]
