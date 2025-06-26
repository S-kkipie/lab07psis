#include "EntidadBancaria.h"
#include "ExcepcionesSistema.h"

EntidadBancaria::EntidadBancaria(string nombre) : nombre(nombre) {}

Boveda* EntidadBancaria::obtenerBoveda(string plaza) {
    for (auto &b : bovedas) {
        if (b.plaza == plaza) return &b;
    }
    throw ExcepcionEntidad("Bóveda no encontrada en la entidad bancaria");
}

void EntidadBancaria::agregarBoveda(Boveda b) {
    bovedas.push_back(b);
}
