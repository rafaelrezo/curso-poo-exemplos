#ifndef CONTROLADOR_ESTACAO_HPP
#define CONTROLADOR_ESTACAO_HPP

#include <string>

#include "estrategia_controle.hpp"
#include "tipo_comando.hpp"

class ControladorEstacao {
private:
    const EstrategiaControle& estrategia;

public:
    explicit ControladorEstacao(const EstrategiaControle& estrategiaControle)
        : estrategia(estrategiaControle) {}

    TipoComando avaliar(double nivel, double pressao) const {
        return estrategia.decidir(nivel, pressao);
    }

    std::string nomeDaEstrategia() const {
        return estrategia.nome();
    }
};

#endif

