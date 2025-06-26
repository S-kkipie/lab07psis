#ifndef MONEDA_H
#define MONEDA_H
#include <string>
using namespace std;

class Moneda {
public:
    string nombre;
    string simbolo;
    Moneda(string nombre, string simbolo) : nombre(nombre), simbolo(simbolo) {}
};

#endif // MONEDA_H
