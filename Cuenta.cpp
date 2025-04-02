/**
* Archivo: Cuenta.cpp
* Descripción: Implementación de los métodos de la clase Cuenta.
*              Permite administrar una cuenta bancaria realizando depósitos y retiros.
*/

#include <iostream>
#include "Cuenta.h"

Cuenta::Cuenta(std::string numeroCuenta, std::string nombreCompleto, double saldo) {
    /**
    * Constructor de la cuenta.
    * Args:
    *   std::string numeroCuenta: cadena de texto con un código numérico único que identifica la cuenta.
    *   std::string nombreCompleto: nombres y apellidos del titular de la cuenta.
    *   double saldo: monto de dinero actual de la cuenta.
    * Return:
    *   Cuenta: objeto de la clase cuenta correspondiente.
    */
    this -> numeroCuenta = numeroCuenta;
    this -> nombreCompleto = nombreCompleto;
    this -> saldo = saldo;
};

Cuenta::Cuenta() {
    /**
     *Constructor por defecto de la cuenta.
     */
    this -> numeroCuenta = "";
    this -> nombreCompleto = "";
    this -> saldo = 0.0;
}

Cuenta::~Cuenta() {
    /**
    * Destructor de la cuenta.
    */
}

void Cuenta::setNombreCompleto(std::string nombreCompleto) {
    /**
    * Setter para establecer o actualizar el nombre completo del titular de la cuenta.
    * Args:
    *   std::string numeroCuenta: cadena de texto con nombres y apellidos del titular de la cuenta.
    */
    this -> nombreCompleto = nombreCompleto;
}

std::string Cuenta::getNumeroCuenta() {
    /**
    * Getter para retornar el número de cuenta.
    * Return:
    *  std::String: cadena de texto con un código numérico único que identifica la cuenta.
    */
    return numeroCuenta;
}

std::string Cuenta::getNombreCompleto() {
    /**
    * Getter para retornar el nombre completo del titular de la cuenta.
    * Return:
    *  std::String: nombres y apellidos del titular de la cuenta.
    */
    return nombreCompleto;
}

double Cuenta::getSaldo() {
    /**
    * Getter para retornar el saldo disponible en la cuenta.
    * Return:
    *   double: monto de dinero actual de la cuenta.
    */
    return saldo;
}

void Cuenta::depositar(double cantidadDeposito) {
    /**
    * Incrementa el saldo disponible en la cuenta por un monto especificado.
    */
    this -> saldo += cantidadDeposito;
    std::cout << std::endl << "Se realizón un depósito por un monto de " << cantidadDeposito << std::endl;
    std::cout << "El saldo actual es de " << saldo << std::endl;
}

void Cuenta::retirar(double cantidadRetiro) {
    /**
    * Disminuye el saldo de la cuenta en un monto especificado.
    * Si el saldo es insuficiente, la operación no se realiza.
    */
    if (cantidadRetiro <= saldo) {
        this -> saldo -= cantidadRetiro;
        std::cout << std::endl << "Se realizón un retiro por un monto de " << cantidadRetiro << std::endl;
        std::cout << "El saldo actual es de " << saldo << std::endl;
    } else {
        std::cout << "Saldo insuficiente" << std::endl;
        std::cout << "No fue posible realizar el retiro." << std::endl;
    }
}