from modelos import EventoOperacional, Leitura
from observadores import ObservadorEvento


class MonitorEventos:
    def __init__(self) -> None:
        self._observadores: list[ObservadorEvento] = []

    def adicionar_observador(self, observador: ObservadorEvento) -> None:
        self._observadores.append(observador)

    def publicar(self, evento: EventoOperacional) -> None:
        for observador in self._observadores:
            observador.notificar(evento)

    def avaliar_leitura(self, leitura: Leitura) -> None:
        if leitura.status == "falha":
            self.publicar(EventoOperacional(
                timestamp=leitura.timestamp,
                origem=leitura.tag,
                tipo="LEITURA_INVALIDA",
                mensagem="Leitura marcada como falha pelo controlador",
                severidade="media",
            ))
            return

        if leitura.tipo == "pressao" and leitura.valor is not None and leitura.valor > 6.0:
            self.publicar(EventoOperacional(
                timestamp=leitura.timestamp,
                origem=leitura.tag,
                tipo="PRESSAO_ALTA",
                mensagem="Pressao acima do limite seguro",
                severidade="alta",
            ))

        if leitura.tipo == "nivel" and leitura.valor is not None and leitura.valor > 90.0:
            self.publicar(EventoOperacional(
                timestamp=leitura.timestamp,
                origem=leitura.tag,
                tipo="NIVEL_CRITICO",
                mensagem="Nivel acima do limite critico",
                severidade="alta",
            ))
