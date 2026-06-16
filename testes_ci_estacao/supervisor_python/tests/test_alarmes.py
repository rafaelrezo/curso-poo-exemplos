import pytest

from estacao.alarmes import gerar_alarmes
from estacao.modelos import Leitura


@pytest.mark.parametrize(
    ("tag", "valor", "alarme_esperado"),
    [
        ("PT-201", 7.2, "PRESSAO_ALTA"),
        ("LT-101", 92.0, "NIVEL_CRITICO"),
        ("FT-301", 11.5, "BAIXA_VAZAO"),
    ],
)
def test_condicoes_criticas_geram_alarmes(tag, valor, alarme_esperado):
    leitura = Leitura(
        timestamp="2026-06-09T10:30:00-03:00",
        tag=tag,
        valor=valor,
        unidade="%",
        status="alerta",
    )

    alarmes = gerar_alarmes(leitura)

    assert len(alarmes) == 1
    assert alarmes[0].alarme == alarme_esperado


def test_leitura_normal_nao_gera_alarme():
    leitura = Leitura(
        timestamp="2026-06-09T10:30:00-03:00",
        tag="LT-101",
        valor=50.0,
        unidade="%",
        status="operando",
    )

    assert gerar_alarmes(leitura) == []

