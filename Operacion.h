#ifndef OPERACION_H
#define OPERACION_H
#include <string>
#include <map>
#include "Transportadora.h"
#include "EntidadBancaria.h"
using namespace std;

class Operacion {
public:
    string fecha;
    string tipo;
    map<int, int> denominaciones;
    string tipoActivo;
    Transportadora *transportadora;
    string plaza;
    EntidadBancaria *origen;
    EntidadBancaria *destino;
    Operacion(string fecha, string tipo, map<int, int> denoms, string tipoActivo, Transportadora *t, string plaza, EntidadBancaria *origen, EntidadBancaria *destino);
    int calcularTotal();
};

#endif // OPERACION_H
