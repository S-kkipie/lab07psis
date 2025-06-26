#include "Operacion.h"
#include "ExcepcionesSistema.h"

Operacion::Operacion(
    string fecha, string tipo, map<Moneda*, int> monedas,
    string tipoActivo, Transportadora *t, string plaza,
    EntidadBancaria *origen, EntidadBancaria *destino)
    : fecha(fecha), tipo(tipo), monedas(monedas), tipoActivo(tipoActivo),
      transportadora(t), plaza(plaza), origen(origen), destino(destino) {
    if (tipo != "Deposito" && tipo != "Retiro" && tipo != "Traslado") {
        throw ExcepcionOperacion("Tipo de operación inválido");
    }
    if (!t || !origen || !destino) {
        throw ExcepcionOperacion("Transportadora, origen o destino nulo");
    }
    for (const auto &m : monedas) {
        if (!m.first || m.second < 0) {
            throw ExcepcionOperacion("Moneda nula o cantidad inválida");
        }
    }
}

double Operacion::calcularTotal() {
    double total = 0.0;
    for (auto &m : monedas) {
        total += m.first->valor * m.second;
    }
    if (total <= 0) {
        throw ExcepcionOperacion("El total de la operación debe ser mayor a cero");
    }
    return total;
}
