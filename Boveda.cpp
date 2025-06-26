#include "Boveda.h"
#include <iostream>

Boveda::Boveda(string plaza) : plaza(plaza) {}

void Boveda::actualizarSaldo(string tipo, int cantidad) {
    if (saldos[tipo] + cantidad < 0) {
        throw std::runtime_error("Saldo insuficiente para la operación en la boveda " + plaza);
    }
    saldos[tipo] += cantidad;
}

int Boveda::consultarSaldo(string tipo) {
    if (saldos.find(tipo) == saldos.end()) {
        return 0;
    }
    return saldos[tipo];
}
