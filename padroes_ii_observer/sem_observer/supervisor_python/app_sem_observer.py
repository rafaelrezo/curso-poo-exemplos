from dataclasses import dataclass


@dataclass
class Leitura:
    timestamp: str
    tag: str
    tipo: str
    valor: float | None
    unidade: str
    status: str


def processar_leituras(leituras: list[Leitura]) -> tuple[list[dict], list[dict]]:
    alarmes: list[dict] = []
    historico: list[dict] = []

    for leitura in leituras:
        if leitura.status == "falha":
            evento = {
                "timestamp": leitura.timestamp,
                "origem": leitura.tag,
                "tipo": "LEITURA_INVALIDA",
                "mensagem": "Leitura marcada como falha pelo controlador",
                "severidade": "media",
            }
            alarmes.append(evento)
            historico.append(evento)
            print(f"[EVENTO] {evento['origem']} - {evento['tipo']}")
            continue

        if leitura.tipo == "pressao" and leitura.valor is not None and leitura.valor > 6.0:
            evento = {
                "timestamp": leitura.timestamp,
                "origem": leitura.tag,
                "tipo": "PRESSAO_ALTA",
                "mensagem": "Pressao acima do limite seguro",
                "severidade": "alta",
            }
            alarmes.append(evento)
            historico.append(evento)
            print(f"[EVENTO] {evento['origem']} - {evento['tipo']}")

        if leitura.tipo == "nivel" and leitura.valor is not None and leitura.valor > 90.0:
            evento = {
                "timestamp": leitura.timestamp,
                "origem": leitura.tag,
                "tipo": "NIVEL_CRITICO",
                "mensagem": "Nivel acima do limite critico",
                "severidade": "alta",
            }
            alarmes.append(evento)
            historico.append(evento)
            print(f"[EVENTO] {evento['origem']} - {evento['tipo']}")

    return alarmes, historico


def main() -> None:
    leituras = [
        Leitura("2026-06-10T10:00:00-03:00", "PT-201", "pressao", 7.2, "bar", "alerta"),
        Leitura("2026-06-10T10:00:01-03:00", "LT-101", "nivel", 92.0, "%", "alerta"),
        Leitura("2026-06-10T10:00:02-03:00", "FT-301", "vazao", None, "m3/h", "falha"),
    ]

    alarmes, historico = processar_leituras(leituras)

    print(f"Alarmes ativos: {len(alarmes)}")
    print(f"Eventos no historico: {len(historico)}")


if __name__ == "__main__":
    main()
