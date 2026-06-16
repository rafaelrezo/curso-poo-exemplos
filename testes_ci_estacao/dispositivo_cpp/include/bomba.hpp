#ifndef BOMBA_HPP
#define BOMBA_HPP

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

#endif

