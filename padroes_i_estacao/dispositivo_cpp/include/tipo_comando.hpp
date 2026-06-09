#ifndef TIPO_COMANDO_HPP
#define TIPO_COMANDO_HPP

#include <string>

enum class TipoComando {
    Nenhum,
    LigarBomba,
    DesligarBomba,
    BloquearPartida
};

inline std::string comandoParaTexto(TipoComando comando) {
    if (comando == TipoComando::LigarBomba) {
        return "LIGAR_BOMBA";
    }

    if (comando == TipoComando::DesligarBomba) {
        return "DESLIGAR_BOMBA";
    }

    if (comando == TipoComando::BloquearPartida) {
        return "BLOQUEAR_PARTIDA";
    }

    return "NENHUM";
}

#endif
