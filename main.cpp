#include <iostream>
#include <map>
#include "SistemaBovedas.h"
#include "Moneda.h"
#include "ExcepcionesSistema.h"
using namespace std;

int main() {
    try {
        SistemaBovedas sistema;
        EntidadBancaria bancoA("Banco A");
        EntidadBancaria bancoB("Banco B");
        bancoA.agregarBoveda(Boveda("Lima"));
        bancoB.agregarBoveda(Boveda("Lima"));
        sistema.agregarBanco(&bancoA);
        sistema.agregarBanco(&bancoB);
        Transportadora prosegur("Prosegur");
        sistema.agregarTransportadora(prosegur);
        Moneda soles("Soles", "S/", 1.0);
        map<Moneda*, int> monedas = {{&soles, 5}, {&soles, 2}}; 
        Operacion op(
            "2025-05-06", "Traslado", monedas, "soles",
            &prosegur, "Lima", &bancoA, &bancoB);
        bancoA.obtenerBoveda("Lima")->actualizarSaldo("soles", 1000);
        sistema.registrarOperacion(op);
        sistema.mostrarSaldo("Banco A", "Lima", "soles");
        sistema.mostrarSaldo("Banco B", "Lima", "soles");
    } catch (const ExcepcionSistema &e) {
        cerr << "Excepción del sistema: " << e.what() << endl;
    } catch (const exception &e) {
        cerr << "Excepción estándar: " << e.what() << endl;
    }
    return 0;
}
