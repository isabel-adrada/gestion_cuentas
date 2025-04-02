/**
* Archivo: Banco.cpp
* Descripción: Implementación de los métodos de la clase Banco.
*              Contiene funciones para buscar cuentas por nombre del titular o número de cuenta.
*/

#include "Banco.h"

Banco::Banco() {
    this -> nombre = "Banco Grupo 1";
    this -> cuentas = {};
}

Banco::~Banco() {
    /**
    * Destructor del banco.
    */
}

void Banco::registrarCuenta(Cuenta &cuenta) {
    /**
    * Agrega un objeto de la clase cuenta al final del vector<string> cuentas.
    */
    this -> cuentas.push_back(cuenta);
}

std::string Banco::getNombre() {
    /**
    * Getter para retornar el nombre del banco.
    * Return:
    *   std::string: cadena de caracteres con el nombre del banco.
    */
    return nombre;
};

std::vector<Cuenta> Banco::getCuentas() {
    /**
    * Getter para retornar todas las cuentas del banco.
    * Return:
    *   std::vector<Cuentas>: vector que contiene todos los objetos de tipo Cuenta del banco.
    */
    return cuentas;
};


Cuenta Banco::getCuentaNombre(std::string nombreCompleto) {
    /**
    * Busca una cuenta utilizando el nombre del titular.
    * Se recorre la lista de cuentas almacenadas en el banco y se compara el nombre de cada cuenta.
    * Args:
    *   nombreCompleto: nombre completo de la persona cuya cuenta se quiere encontrar.
    * Return:
    *   Una cuenta con los datos correspondientes si se encuentra una coincidencia.
    *   Si no se encuentra, se devuelve una cuenta vacía.
    */
    for (Cuenta cuenta : cuentas) {
        if (nombreCompleto == cuenta.getNombreCompleto()) {
            return cuenta;
        }
    }
    return Cuenta(); // Retorna una cuenta con atributos por defecto si no hay coincidencias.
}
Cuenta Banco::getCuentaNumero(std::string numeroCuenta) {
    /**
    * Busca una cuenta a partir del número de cuenta.
    * Se revisa la lista de cuentas y se compara el número proporcionado con los registros existentes.
    * Args:
    *   numeroCuenta: número de cuenta que se quiere buscar en la base de datos del banco.
    * Return:
    *   La cuenta correspondiente si se encuentra en los registros.
    *   Si no existe, devuelve una cuenta vacía.
    */
    for (Cuenta cuenta : cuentas) {
        if (numeroCuenta == cuenta.getNumeroCuenta()) {
            return cuenta;
        }
    }
    return Cuenta(); // Retorna una cuenta con atributps por defecto si no hay coincidencias.
}

