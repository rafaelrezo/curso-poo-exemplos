#ifndef REGISTRADOR_EVENTOS_HPP
#define REGISTRADOR_EVENTOS_HPP

#include <iostream>

#include "evento_operacional.hpp"
#include "observador_evento.hpp"

class RegistradorEventos : public ObservadorEvento {
public:
    void notificar(const EventoOperacional& evento) override {
        std::cout << "[HISTORICO] salvando "
                  << evento.tipo
                  << " de "
                  << evento.origem
                  << "\n";
    }
};

#endif
