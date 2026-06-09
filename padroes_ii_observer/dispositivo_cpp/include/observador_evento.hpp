#ifndef OBSERVADOR_EVENTO_HPP
#define OBSERVADOR_EVENTO_HPP

#include "evento_operacional.hpp"

class ObservadorEvento {
public:
    virtual ~ObservadorEvento() = default;

    virtual void notificar(const EventoOperacional& evento) = 0;
};

#endif
