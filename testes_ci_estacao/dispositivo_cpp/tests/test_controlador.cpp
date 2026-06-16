#include <cassert>
#include <string>

#include "bomba.hpp"
#include "comando.hpp"
#include "controlador_estacao.hpp"
#include "estrategia_controle.hpp"
#include "telemetria.hpp"
#include "tipo_comando.hpp"

void controle_normal_deve_ligar_bomba_quando_nivel_baixo() {
    ControleNormal regra;
    ControladorEstacao controlador(regra);

    TipoComando comando = controlador.avaliar(25.0, 2.0);

    assert(comando == TipoComando::LigarBomba);
}

void controle_normal_deve_desligar_bomba_quando_nivel_alto() {
    ControleNormal regra;
    ControladorEstacao controlador(regra);

    TipoComando comando = controlador.avaliar(85.0, 2.0);

    assert(comando == TipoComando::DesligarBomba);
}

void controle_normal_deve_bloquear_partida_quando_pressao_alta() {
    ControleNormal regra;
    ControladorEstacao controlador(regra);

    TipoComando comando = controlador.avaliar(25.0, 7.0);

    assert(comando == TipoComando::BloquearPartida);
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

void telemetria_deve_gerar_json_do_contrato() {
    LeituraSensor leitura{
        "LT-101",
        42.0,
        "%",
        "2026-06-09T10:00:00-03:00",
        "operando"
    };

    std::string json = formatarJsonLeitura(leitura);

    assert(json.find("\"tag\":\"LT-101\"") != std::string::npos);
    assert(json.find("\"valor\":42.00") != std::string::npos);
    assert(json.find("\"unidade\":\"%\"") != std::string::npos);
    assert(json.find("\"timestamp\":\"2026-06-09T10:00:00-03:00\"") != std::string::npos);
    assert(json.find("\"status\":\"operando\"") != std::string::npos);
}

int main() {
    controle_normal_deve_ligar_bomba_quando_nivel_baixo();
    controle_normal_deve_desligar_bomba_quando_nivel_alto();
    controle_normal_deve_bloquear_partida_quando_pressao_alta();
    comando_deve_bloquear_bomba_e_desligar();
    telemetria_deve_gerar_json_do_contrato();
    return 0;
}

