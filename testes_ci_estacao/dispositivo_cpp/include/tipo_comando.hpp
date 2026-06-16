#ifndef TIPO_COMANDO_HPP
#define TIPO_COMANDO_HPP

#include <string>

enum class TipoComando {
    Nenhum,
    LigarBomba,
    DesligarBomba,
    BloquearPartida
};

inline std::string comandoParaTexto(TipoComando tipo) {
    switch (tipo) {
        case TipoComando::LigarBomba:
            return "LIGAR_BOMBA";
        case TipoComando::DesligarBomba:
            return "DESLIGAR_BOMBA";
        case TipoComando::BloquearPartida:
            return "BLOQUEAR_PARTIDA";
        case TipoComando::Nenhum:
        default:
            return "NENHUM";
    }
}

#endif

