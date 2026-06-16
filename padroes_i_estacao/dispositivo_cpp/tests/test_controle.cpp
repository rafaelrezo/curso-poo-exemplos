#include <cassert>

#include "bomba.hpp"
#include "comando.hpp"
#include "estrategia_controle.hpp"
#include "tipo_comando.hpp"

void deve_ligar_bomba_quando_nivel_baixo() {
    ControleNormal regra;

    TipoComando comando = regra.decidir(25.0, 2.0);

    assert(comando == TipoComando::LigarBomba);
}

void deve_desligar_bomba_quando_nivel_alto() {
    ControleNormal regra;

    TipoComando comando = regra.decidir(85.0, 2.0);

    assert(comando == TipoComando::DesligarBomba);
}

void deve_bloquear_partida_quando_pressao_alta() {
    ControleNormal regra;

    TipoComando comando = regra.decidir(25.0, 7.0);

    assert(comando == TipoComando::BloquearPartida);
}

void comando_deve_ligar_bomba_quando_nao_estiver_bloqueada() {
    Bomba bomba;
    LigarBomba comando;

    comando.executar(bomba);

    assert(bomba.estaLigada());
    assert(!bomba.estaBloqueada());
}

void comando_deve_bloquear_bomba_e_desligar() {
    Bomba bomba;
    LigarBomba ligar;
    BloquearPartida bloquear;

    ligar.executar(bomba);
    bloquear.executar(bomba);

    assert(bomba.estaBloqueada());
    assert(!bomba.estaLigada());
}

int main() {
    deve_ligar_bomba_quando_nivel_baixo();
    deve_desligar_bomba_quando_nivel_alto();
    deve_bloquear_partida_quando_pressao_alta();
    comando_deve_ligar_bomba_quando_nao_estiver_bloqueada();
    comando_deve_bloquear_bomba_e_desligar();
    return 0;
}
