from estacao.modelos import Alarme, Leitura


def gerar_alarmes(leitura: Leitura) -> list[Alarme]:
    alarmes: list[Alarme] = []

    if leitura.tag.startswith("PT") and leitura.valor > 6.0:
        alarmes.append(Alarme(
            origem=leitura.tag,
            alarme="PRESSAO_ALTA",
            severidade="alta",
            timestamp=leitura.timestamp,
        ))

    if leitura.tag.startswith("LT") and leitura.valor > 90.0:
        alarmes.append(Alarme(
            origem=leitura.tag,
            alarme="NIVEL_CRITICO",
            severidade="alta",
            timestamp=leitura.timestamp,
        ))

    if leitura.tag.startswith("FT") and leitura.valor < 12.0:
        alarmes.append(Alarme(
            origem=leitura.tag,
            alarme="BAIXA_VAZAO",
            severidade="media",
            timestamp=leitura.timestamp,
        ))

    return alarmes

