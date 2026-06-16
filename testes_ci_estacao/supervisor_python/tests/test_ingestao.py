from pathlib import Path

import pytest

from estacao.ingestao import ler_jsonl


def test_ler_jsonl_valido():
    caminho = Path("../dados/leituras_exemplo.jsonl")

    leituras = ler_jsonl(caminho)

    assert len(leituras) == 3
    assert leituras[0].tag == "LT-101"
    assert leituras[1].tag == "PT-201"
    assert leituras[2].tag == "FT-301"


def test_ler_jsonl_invalido_falha_com_linha(tmp_path):
    caminho = tmp_path / "leituras_invalidas.jsonl"
    caminho.write_text('{"tag": "LT-101"}\n{json quebrado}\n', encoding="utf-8")

    with pytest.raises(ValueError):
        ler_jsonl(caminho)

