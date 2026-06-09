#include <iostream>
#include <string>

class Bomba {
private:
    bool ligada = false;
    bool bloqueada = false;

public:
    void ligar() {
        if (!bloqueada) {
            ligada = true;
        }
    }

    void desligar() {
        ligada = false;
    }

    void bloquear() {
        bloqueada = true;
        ligada = false;
    }

    bool estaLigada() const {
        return ligada;
    }

    bool estaBloqueada() const {
        return bloqueada;
    }
};

class ControladorEstacao {
public:
    std::string avaliar(double nivel, double pressao, const std::string& modo) {
        if (modo == "normal") {
            if (pressao > 6.0) {
                return "BLOQUEAR_PARTIDA";
            }
            if (nivel < 30.0) {
                return "LIGAR_BOMBA";
            }
            if (nivel > 80.0) {
                return "DESLIGAR_BOMBA";
            }
        }

        if (modo == "economico") {
            if (pressao > 5.5) {
                return "BLOQUEAR_PARTIDA";
            }
            if (nivel < 20.0) {
                return "LIGAR_BOMBA";
            }
            if (nivel > 75.0) {
                return "DESLIGAR_BOMBA";
            }
        }

        return "NENHUM";
    }

    void executar(const std::string& comando, Bomba& bomba) {
        if (comando == "LIGAR_BOMBA") {
            bomba.ligar();
        } else if (comando == "DESLIGAR_BOMBA") {
            bomba.desligar();
        } else if (comando == "BLOQUEAR_PARTIDA") {
            bomba.bloquear();
        }
    }

    void registrar(const std::string& comando) {
        std::cout << "Comando executado: " << comando << "\n";
    }
};

int main() {
    const double nivel = 25.0;
    const double pressao = 2.0;
    const std::string modo = "normal";

    Bomba bomba;
    ControladorEstacao controlador;

    std::string comando = controlador.avaliar(nivel, pressao, modo);
    controlador.executar(comando, bomba);
    controlador.registrar(comando);

    std::cout << "Bomba ligada? " << (bomba.estaLigada() ? "sim" : "nao") << "\n";
    std::cout << "Bomba bloqueada? " << (bomba.estaBloqueada() ? "sim" : "nao") << "\n";

    return 0;
}
