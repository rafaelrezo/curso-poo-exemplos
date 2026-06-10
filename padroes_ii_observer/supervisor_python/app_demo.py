from modelos import Leitura
from monitor_eventos import MonitorEventos
from observadores import GerenciadorAlarmes, LoggerConsole, RepositorioEventosMemoria


def main() -> None:
    monitor = MonitorEventos()
    alarmes = GerenciadorAlarmes()
    logger = LoggerConsole()
    repositorio_eventos = RepositorioEventosMemoria()

    monitor.adicionar_observador(alarmes)
    monitor.adicionar_observador(logger)
    monitor.adicionar_observador(repositorio_eventos)

    leituras = [
        Leitura("2026-06-10T10:00:00-03:00", "PT-201", "pressao", 7.2, "bar", "alerta"),
        Leitura("2026-06-10T10:00:01-03:00", "LT-101", "nivel", 92.0, "%", "alerta"),
        Leitura("2026-06-10T10:00:02-03:00", "FT-301", "vazao", None, "m3/h", "falha"),
    ]

    for leitura in leituras:
        monitor.avaliar_leitura(leitura)

    print(f"Alarmes ativos: {len(alarmes.listar())}")
    print(f"Eventos no historico: {len(repositorio_eventos.listar())}")


if __name__ == "__main__":
    main()
