#ifndef OPERACION_H
#define OPERACION_H
#include <string>
#include <map>
#include "Transportadora.h"
#include "EntidadBancaria.h"
#include "Moneda.h"
using namespace std;

class Operacion {
public:
    string fecha;
    string tipo;
    map<Moneda*, int> monedas;
    string tipoActivo;
    Transportadora *transportadora;
    string plaza;
    EntidadBancaria *origen;
    EntidadBancaria *destino;
    Operacion(string fecha, string tipo, map<Moneda*, int> monedas, string tipoActivo, Transportadora *t, string plaza, EntidadBancaria *origen, EntidadBancaria *destino);
    double calcularTotal();
};

#endif // OPERACION_H
