#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Boveda
{
public:
    string plaza;
    map<string, int> saldos;
    Boveda(string plaza) : plaza(plaza) {}

    void actualizarSaldo(string tipo, int cantidad)
    {
        cout << "Actualizando saldo de " << tipo << " en " << plaza << endl;
        saldos[tipo] += cantidad;
    }

    int consultarSaldo(string tipo)
    {
        return saldos[tipo];
    }
};

class EntidadBancaria
{
public:
    string nombre;
    vector<Boveda> bovedas;

    EntidadBancaria(string nombre) : nombre(nombre) {}

    Boveda* obtenerBoveda(string plaza)
    {
        for (auto &b : bovedas)
        {
            if (b.plaza == plaza)
                return &b;
        }
        return nullptr;
    }

    void agregarBoveda(Boveda b)
    {
        bovedas.push_back(b);
    }
};

class Transportadora
{
public:
    string nombre;
    Transportadora(string nombre) : nombre(nombre) {}
};

class Operacion
{
public:
    string fecha;
    string tipo;                  // Retiro, Depósito, Traslado, etc.
    map<int, int> denominaciones; // Ej: {200: 5, 100: 3}
    string tipoActivo;            // soles, bonos, etc.
    Transportadora *transportadora;
    string plaza;
    EntidadBancaria *origen;
    EntidadBancaria *destino;
    Operacion(
        string fecha, string tipo, map<int, int> denoms,
        string tipoActivo, Transportadora *t, string plaza,
        EntidadBancaria *origen, EntidadBancaria *destino)
        : fecha(fecha), tipo(tipo), denominaciones(denoms), tipoActivo(tipoActivo),
          transportadora(t), plaza(plaza), origen(origen), destino(destino) {}

    int calcularTotal()
    {
        int total = 0;
        for (auto &d : denominaciones)
        {
            total += d.first * d.second;
        }
        return total;
    }
};

class SistemaBovedas
{
private:
    vector<EntidadBancaria*> bancos;
    vector<Transportadora> transportadoras;
    vector<Operacion> operaciones;

public:
    void agregarBanco(EntidadBancaria *banco)
    {
        bancos.push_back(banco);
    }

    void agregarTransportadora(Transportadora t)
    {
        transportadoras.push_back(t);
    }

    void registrarOperacion(Operacion op)
    {
        int total = op.calcularTotal();
        Boveda *boveda_origen = op.origen->obtenerBoveda(op.plaza);
        Boveda *boveda_destino = op.destino->obtenerBoveda(op.plaza);
        if (op.tipo == "Deposito")
        {
            boveda_destino->actualizarSaldo(op.tipoActivo, total);
        }
        else if (op.tipo == "Retiro")
        {
            if (boveda_origen->consultarSaldo(op.tipoActivo) >= total)
            {
                boveda_origen->actualizarSaldo(op.tipoActivo, -total);
            }
            else
            {
                cout << "ERROR: Saldo insuficiente en " << op.plaza << endl;
                return;
            }
        }
        else if (op.tipo == "Traslado")
        {
            if (boveda_origen->consultarSaldo(op.tipoActivo) >= total)
            {
                boveda_origen->actualizarSaldo(op.tipoActivo, -total);
                boveda_destino->actualizarSaldo(op.tipoActivo, total);
            }
            else
            {
                cout << "ERROR: Saldo insuficiente para traslado.\n";
                return;
            }
        }
        operaciones.push_back(op);
        cout << "Operación registrada correctamente.\n";
    }

    void mostrarSaldo(string banco_nombre, string plaza, string tipoActivo)
    {
        for (auto banco : bancos)
        {
            if (banco->nombre == banco_nombre)
            {
                Boveda *b = banco->obtenerBoveda(plaza);
                if (b)
                {
                    cout << "Saldo en " << banco_nombre << " (" << plaza << ") de " << tipoActivo
                         << ": " << b->consultarSaldo(tipoActivo) << endl;
                }
            }
        }
    }
};

int main()
{
    SistemaBovedas sistema;
    EntidadBancaria bancoA("Banco A");
    EntidadBancaria bancoB("Banco B");
    bancoA.agregarBoveda(Boveda("Lima"));
    bancoB.agregarBoveda(Boveda("Lima"));
    sistema.agregarBanco(&bancoA);
    sistema.agregarBanco(&bancoB);
    Transportadora prosegur("Prosegur");
    sistema.agregarTransportadora(prosegur);
    map<int, int> denoms = {{100, 5}, {50, 2}}; // total: 100*5 + 50*2 = 600
    Operacion op(
        "2025-05-06", "Traslado", denoms, "soles",
        &prosegur, "Lima", &bancoA, &bancoB);
    // int sumaOperacion = op.calcularTotal();
    // cout << "Total de la operación: " << sumaOperacion << endl;
    bancoA.obtenerBoveda("Lima")->actualizarSaldo("soles", 1000); // Banco A tiene 1000
    sistema.registrarOperacion(op);
    sistema.mostrarSaldo("Banco A", "Lima", "soles");
    sistema.mostrarSaldo("Banco B", "Lima", "soles");
    return 0;
}