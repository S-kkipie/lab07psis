#ifndef EXCEPCIONESSISTEMA_H
#define EXCEPCIONESSISTEMA_H
#include <stdexcept>
#include <string>

class ExcepcionSistema : public std::runtime_error {
public:
    explicit ExcepcionSistema(const std::string& msg) : std::runtime_error(msg) {}
};

class ExcepcionOperacion : public ExcepcionSistema {
public:
    explicit ExcepcionOperacion(const std::string& msg) : ExcepcionSistema(msg) {}
};

class ExcepcionEntidad : public ExcepcionSistema {
public:
    explicit ExcepcionEntidad(const std::string& msg) : ExcepcionSistema(msg) {}
};

class ExcepcionTransportadora : public ExcepcionSistema {
public:
    explicit ExcepcionTransportadora(const std::string& msg) : ExcepcionSistema(msg) {}
};

#endif // EXCEPCIONESSISTEMA_H
