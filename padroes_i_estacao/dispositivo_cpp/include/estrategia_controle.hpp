#ifndef ESTRATEGIA_CONTROLE_HPP
#define ESTRATEGIA_CONTROLE_HPP

#include <string>

#include "tipo_comando.hpp"

class EstrategiaControle {
public:
    virtual ~EstrategiaControle() = default;

    virtual TipoComando decidir(double nivel, double pressao) const = 0;
    virtual std::string nome() const = 0;
};

class ControleNormal : public EstrategiaControle {
public:
    TipoComando decidir(double nivel, double pressao) const override {
        if (pressao > 6.0) {
            return TipoComando::BloquearPartida;
        }

        if (nivel < 30.0) {
            return TipoComando::LigarBomba;
        }

        if (nivel > 80.0) {
            return TipoComando::DesligarBomba;
        }

        return TipoComando::Nenhum;
    }

    std::string nome() const override {
        return "ControleNormal";
    }
};

class ControleEconomico : public EstrategiaControle {
public:
    TipoComando decidir(double nivel, double pressao) const override {
        if (pressao > 5.5) {
            return TipoComando::BloquearPartida;
        }

        if (nivel < 20.0) {
            return TipoComando::LigarBomba;
        }

        if (nivel > 75.0) {
            return TipoComando::DesligarBomba;
        }

        return TipoComando::Nenhum;
    }

    std::string nome() const override {
        return "ControleEconomico";
    }
};

#endif
