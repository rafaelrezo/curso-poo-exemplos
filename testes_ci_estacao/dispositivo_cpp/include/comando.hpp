#ifndef COMANDO_HPP
#define COMANDO_HPP

#include <memory>
#include <string>

#include "bomba.hpp"
#include "tipo_comando.hpp"

class Comando {
public:
    virtual ~Comando() = default;

    virtual void executar(Bomba& bomba) const = 0;
    virtual std::string nome() const = 0;
};

class LigarBomba : public Comando {
public:
    void executar(Bomba& bomba) const override {
        bomba.ligar();
    }

    std::string nome() const override {
        return "LIGAR_BOMBA";
    }
};

class DesligarBomba : public Comando {
public:
    void executar(Bomba& bomba) const override {
        bomba.desligar();
    }

    std::string nome() const override {
        return "DESLIGAR_BOMBA";
    }
};

class BloquearPartida : public Comando {
public:
    void executar(Bomba& bomba) const override {
        bomba.bloquear();
    }

    std::string nome() const override {
        return "BLOQUEAR_PARTIDA";
    }
};

inline std::unique_ptr<Comando> criarComando(TipoComando tipo) {
    if (tipo == TipoComando::LigarBomba) {
        return std::make_unique<LigarBomba>();
    }

    if (tipo == TipoComando::DesligarBomba) {
        return std::make_unique<DesligarBomba>();
    }

    if (tipo == TipoComando::BloquearPartida) {
        return std::make_unique<BloquearPartida>();
    }

    return nullptr;
}

#endif

