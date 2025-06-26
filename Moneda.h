#ifndef MONEDA_H
#define MONEDA_H
#include <string>
using namespace std;

class Moneda {
public:
    string nombre;
    string simbolo;
    double valor; // Valor de la moneda (por ejemplo, en pesos)
    Moneda(string nombre, string simbolo, double valor)
        : nombre(nombre), simbolo(simbolo), valor(valor) {}
};

#endif // MONEDA_H
