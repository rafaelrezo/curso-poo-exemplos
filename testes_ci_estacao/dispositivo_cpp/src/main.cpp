#include <iostream>
#include <memory>

#include "bomba.hpp"
#include "comando.hpp"
#include "controlador_estacao.hpp"
#include "estrategia_controle.hpp"
#include "telemetria.hpp"
#include "tipo_comando.hpp"

int main() {
    const double nivel = 25.0;
    const double pressao = 2.0;

    ControleNormal regra;
    ControladorEstacao controlador(regra);
    Bomba bomba;

    TipoComando tipo = controlador.avaliar(nivel, pressao);
    std::unique_ptr<Comando> comando = criarComando(tipo);

    std::cout << "Estrategia: " << controlador.nomeDaEstrategia() << "\n";
    std::cout << "Decisao: " << comandoParaTexto(tipo) << "\n";

    if (comando) {
        comando->executar(bomba);
        std::cout << "Comando executado: " << comando->nome() << "\n";
    }

    LeituraSensor leitura{
        "LT-101",
        nivel,
        "%",
        "2026-06-09T10:30:00-03:00",
        bomba.estaLigada() ? "operando" : "parada"
    };

    std::cout << formatarJsonLeitura(leitura) << "\n";
    return 0;
}

