#include "Operacion.h"
#include <stdexcept>

Operacion::Operacion(
    string fecha, string tipo, map<int, int> denoms,
    string tipoActivo, Transportadora *t, string plaza,
    EntidadBancaria *origen, EntidadBancaria *destino)
    : fecha(fecha), tipo(tipo), denominaciones(denoms), tipoActivo(tipoActivo),
      transportadora(t), plaza(plaza), origen(origen), destino(destino) {
    if (tipo != "Deposito" && tipo != "Retiro" && tipo != "Traslado") {
        throw std::invalid_argument("Tipo de operación inválido");
    }
    if (!t || !origen || !destino) {
        throw std::invalid_argument("Transportadora, origen o destino nulo");
    }
    for (const auto &d : denominaciones) {
        if (d.first <= 0 || d.second < 0) {
            throw std::invalid_argument("Denominaciones inválidas");
        }
    }
}

int Operacion::calcularTotal() {
    int total = 0;
    for (auto &d : denominaciones) {
        total += d.first * d.second;
    }
    if (total <= 0) {
        throw std::runtime_error("El total de la operación debe ser mayor a cero");
    }
    return total;
}
