#include <iostream>

#include "estacao_bombeamento.hpp"
#include "gerenciador_alarmes.hpp"
#include "logger_console.hpp"
#include "registrador_eventos.hpp"

int main() {
    EstacaoBombeamento estacao;

    GerenciadorAlarmes gerenciadorAlarmes;
    LoggerConsole logger;
    RegistradorEventos registrador;

    estacao.adicionarObservador(&gerenciadorAlarmes);
    estacao.adicionarObservador(&logger);
    estacao.adicionarObservador(&registrador);

    estacao.avaliarPressao(7.2);
    estacao.avaliarNivel(92.0);

    std::cout << "Alarmes ativos: "
              << gerenciadorAlarmes.listarAlarmes().size()
              << "\n";

    return 0;
}
