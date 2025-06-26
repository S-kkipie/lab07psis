#ifndef ENTIDADBANCARIA_H
#define ENTIDADBANCARIA_H
#include <string>
#include <vector>
#include "Boveda.h"
using namespace std;

class EntidadBancaria {
public:
    string nombre;
    vector<Boveda> bovedas;
    EntidadBancaria(string nombre);
    Boveda* obtenerBoveda(string plaza);
    void agregarBoveda(Boveda b);
};

#endif // ENTIDADBANCARIA_H
