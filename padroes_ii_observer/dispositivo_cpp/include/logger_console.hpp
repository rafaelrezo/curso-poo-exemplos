#ifndef LOGGER_CONSOLE_HPP
#define LOGGER_CONSOLE_HPP

#include <iostream>

#include "evento_operacional.hpp"
#include "observador_evento.hpp"

class LoggerConsole : public ObservadorEvento {
public:
    void notificar(const EventoOperacional& evento) override {
        std::cout << "[EVENTO] "
                  << evento.origem << " - "
                  << evento.tipo << " - "
                  << evento.mensagem << "\n";
    }
};

#endif
