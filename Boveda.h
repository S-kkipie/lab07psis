#ifndef BOVEDA_H
#define BOVEDA_H
#include <string>
#include <map>
#include <stdexcept>
using namespace std;

class Boveda {
public:
    string plaza;
    map<string, int> saldos;
    Boveda(string plaza);
    void actualizarSaldo(string tipo, int cantidad);
    int consultarSaldo(string tipo);
};

#endif // BOVEDA_H
