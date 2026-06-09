#ifndef GERENCIADOR_ALARMES_HPP
#define GERENCIADOR_ALARMES_HPP

#include <vector>

#include "evento_operacional.hpp"
#include "observador_evento.hpp"

class GerenciadorAlarmes : public ObservadorEvento {
private:
    std::vector<EventoOperacional> alarmes;

public:
    void notificar(const EventoOperacional& evento) override {
        if (evento.severidade == "media" || evento.severidade == "alta") {
            alarmes.push_back(evento);
        }
    }

    const std::vector<EventoOperacional>& listarAlarmes() const {
        return alarmes;
    }
};

#endif
