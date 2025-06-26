#ifndef SISTEMABOVEDAS_H
#define SISTEMABOVEDAS_H
#include <vector>
#include <string>
#include "EntidadBancaria.h"
#include "Transportadora.h"
#include "Operacion.h"
using namespace std;

class SistemaBovedas {
private:
    vector<EntidadBancaria*> bancos;
    vector<Transportadora> transportadoras;
    vector<Operacion> operaciones;
public:
    void agregarBanco(EntidadBancaria *banco);
    void agregarTransportadora(Transportadora t);
    void registrarOperacion(Operacion op);
    void mostrarSaldo(string banco_nombre, string plaza, string tipoActivo);
};

#endif // SISTEMABOVEDAS_H
