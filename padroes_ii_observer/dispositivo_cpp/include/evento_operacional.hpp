#ifndef EVENTO_OPERACIONAL_HPP
#define EVENTO_OPERACIONAL_HPP

#include <string>

struct EventoOperacional {
    std::string origem;
    std::string tipo;
    std::string mensagem;
    std::string severidade;
};

#endif
