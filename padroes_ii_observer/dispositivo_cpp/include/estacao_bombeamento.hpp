#ifndef ESTACAO_BOMBEAMENTO_HPP
#define ESTACAO_BOMBEAMENTO_HPP

#include <vector>

#include "evento_operacional.hpp"
#include "observador_evento.hpp"

class EstacaoBombeamento {
private:
    std::vector<ObservadorEvento*> observadores;

public:
    void adicionarObservador(ObservadorEvento* observador) {
        observadores.push_back(observador);
    }

    void publicar(const EventoOperacional& evento) {
        for (auto* observador : observadores) {
            observador->notificar(evento);
        }
    }

    void avaliarPressao(double pressao) {
        if (pressao > 6.0) {
            publicar({
                "PT-201",
                "PRESSAO_ALTA",
                "Pressao acima do limite seguro",
                "alta"
            });
        }
    }

    void avaliarNivel(double nivel) {
        if (nivel > 90.0) {
            publicar({
                "LT-101",
                "NIVEL_CRITICO",
                "Nivel acima do limite critico",
                "alta"
            });
        }
    }
};

#endif
