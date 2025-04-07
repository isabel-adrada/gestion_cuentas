/**
* Archivo: Banco.h
* Descripción: Definición de la clase Banco, que administra un conjunto de cuentas bancarias.
*              Permite buscar cuentas por nombre del titular o por número de cuenta.
*/

#ifndef BANCO_H
#define BANCO_H

#include <map>
#include <string>
#include "Cuenta.h"

class Banco {
private:
    std::string nombre;
    std::map<std::string, Cuenta*> cuentas; ; // Vector de objetos de la clase Cuenta registrados en el banco.

public:
    Banco();
    ~Banco();
    void registrarCuenta(Cuenta* cuenta);
    std::string getNombre();
    std::map<std::string, Cuenta*> getCuentas();
    Cuenta* getCuentaNombre(std::string nombreCompleto);
    Cuenta* getCuentaNumero(std::string numeroCuenta);
};



#endif //BANCO_H
