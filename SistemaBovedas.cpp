#include "SistemaBovedas.h"
#include "ExcepcionesSistema.h"
#include <iostream>

void SistemaBovedas::agregarBanco(EntidadBancaria *banco) {
    if (!banco) throw ExcepcionEntidad("Banco nulo");
    bancos.push_back(banco);
}

void SistemaBovedas::agregarTransportadora(Transportadora t) {
    transportadoras.push_back(t);
}

void SistemaBovedas::registrarOperacion(Operacion op) {
    int total = op.calcularTotal();
    Boveda *boveda_origen = op.origen->obtenerBoveda(op.plaza);
    Boveda *boveda_destino = op.destino->obtenerBoveda(op.plaza);
    if (!boveda_destino && op.tipo != "Retiro") {
        throw ExcepcionEntidad("Bóveda destino no encontrada");
    }
    if (!boveda_origen && op.tipo != "Deposito") {
        throw ExcepcionEntidad("Bóveda origen no encontrada");
    }
    if (op.tipo == "Deposito") {
        boveda_destino->actualizarSaldo(op.tipoActivo, total);
    } else if (op.tipo == "Retiro") {
        boveda_origen->actualizarSaldo(op.tipoActivo, -total);
    } else if (op.tipo == "Traslado") {
        boveda_origen->actualizarSaldo(op.tipoActivo, -total);
        boveda_destino->actualizarSaldo(op.tipoActivo, total);
    }
    operaciones.push_back(op);
    std::cout << "Operación registrada correctamente.\n";
}

void SistemaBovedas::mostrarSaldo(string banco_nombre, string plaza, string tipoActivo) {
    for (auto banco : bancos) {
        if (banco->nombre == banco_nombre) {
            Boveda *b = banco->obtenerBoveda(plaza);
            if (b) {
                std::cout << "Saldo en " << banco_nombre << " (" << plaza << ") de " << tipoActivo
                     << ": " << b->consultarSaldo(tipoActivo) << std::endl;
            } else {
                std::cout << "Bóveda no encontrada para " << banco_nombre << " en " << plaza << std::endl;
            }
        }
    }
}
