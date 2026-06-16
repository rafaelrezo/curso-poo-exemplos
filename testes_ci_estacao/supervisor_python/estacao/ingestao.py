import json
from pathlib import Path

from estacao.modelos import Leitura
from estacao.validacao import validar_leitura


def leitura_de_dict(dados: dict) -> Leitura:
    validar_leitura(dados)
    return Leitura(
        timestamp=dados["timestamp"],
        tag=dados["tag"],
        valor=float(dados["valor"]),
        unidade=dados["unidade"],
        status=dados["status"],
    )


def ler_jsonl(caminho: Path) -> list[Leitura]:
    leituras: list[Leitura] = []

    for numero_linha, linha in enumerate(caminho.read_text(encoding="utf-8").splitlines(), start=1):
        if not linha.strip():
            continue

        try:
            dados = json.loads(linha)
            leituras.append(leitura_de_dict(dados))
        except json.JSONDecodeError as erro:
            raise ValueError(f"JSON invalido na linha {numero_linha}") from erro

    return leituras

