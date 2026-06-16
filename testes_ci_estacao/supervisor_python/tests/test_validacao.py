import pytest

from estacao.validacao import validar_leitura


def test_leitura_valida_deve_passar():
    leitura = {
        "tag": "LT-101",
        "valor": 58.4,
        "unidade": "%",
        "timestamp": "2026-06-09T10:30:00-03:00",
        "status": "operando",
    }

    validar_leitura(leitura)


def test_leitura_sem_tag_deve_falhar():
    leitura = {
        "valor": 58.4,
        "unidade": "%",
        "timestamp": "2026-06-09T10:30:00-03:00",
        "status": "operando",
    }

    with pytest.raises(ValueError):
        validar_leitura(leitura)


def test_valor_textual_deve_falhar_quando_status_operando():
    leitura = {
        "tag": "LT-101",
        "valor": "alto",
        "unidade": "%",
        "timestamp": "2026-06-09T10:30:00-03:00",
        "status": "operando",
    }

    with pytest.raises(TypeError):
        validar_leitura(leitura)

