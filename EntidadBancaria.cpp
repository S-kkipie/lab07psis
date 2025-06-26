#include "EntidadBancaria.h"

EntidadBancaria::EntidadBancaria(string nombre) : nombre(nombre) {}

Boveda* EntidadBancaria::obtenerBoveda(string plaza) {
    for (auto &b : bovedas) {
        if (b.plaza == plaza)
            return &b;
    }
    return nullptr;
}

void EntidadBancaria::agregarBoveda(Boveda b) {
    bovedas.push_back(b);
}
