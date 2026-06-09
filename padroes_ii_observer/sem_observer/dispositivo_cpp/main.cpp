#include <iostream>
#include <string>
#include <vector>

struct Alarme {
    std::string origem;
    std::string tipo;
    std::string mensagem;
    std::string severidade;
};

class EstacaoBombeamento {
private:
    std::vector<Alarme> alarmes;

public:
    void avaliarPressao(double pressao) {
        if (pressao > 6.0) {
            Alarme alarme = {
                "PT-201",
                "PRESSAO_ALTA",
                "Pressao acima do limite seguro",
                "alta"
            };

            alarmes.push_back(alarme);
            imprimirLog(alarme);
            salvarHistorico(alarme);
        }
    }

    void avaliarNivel(double nivel) {
        if (nivel > 90.0) {
            Alarme alarme = {
                "LT-101",
                "NIVEL_CRITICO",
                "Nivel acima do limite critico",
                "alta"
            };

            alarmes.push_back(alarme);
            imprimirLog(alarme);
            salvarHistorico(alarme);
        }
    }

    void imprimirLog(const Alarme& alarme) {
        std::cout << "[EVENTO] "
                  << alarme.origem << " - "
                  << alarme.tipo << " - "
                  << alarme.mensagem << "\n";
    }

    void salvarHistorico(const Alarme& alarme) {
        std::cout << "[HISTORICO] salvando "
                  << alarme.tipo
                  << " de "
                  << alarme.origem
                  << "\n";
    }

    const std::vector<Alarme>& listarAlarmes() const {
        return alarmes;
    }
};

int main() {
    EstacaoBombeamento estacao;

    estacao.avaliarPressao(7.2);
    estacao.avaliarNivel(92.0);

    std::cout << "Alarmes ativos: "
              << estacao.listarAlarmes().size()
              << "\n";

    return 0;
}
