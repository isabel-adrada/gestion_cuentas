/**
 * Archivo: Cuenta.h
 * Descripción: Definición de la clase Cuenta, que representa una cuenta bancaria con su número,
 *              el nombre del titular y el saldo disponible. Permite realizar depósitos y retiros.
 */

#ifndef CUENTA_H
#define CUENTA_H

#include <string>

class Cuenta {
private:
    std::string numeroCuenta; // Cadena de texto con un código numérico único que identifica la cuenta
    std::string nombreCompleto; // Nombres y apellidos del titular de la cuenta.
    double saldo; // Saldo disponible en la cuenta.

public:
    Cuenta();
    Cuenta(std::string numeroCuenta, std::string nombreCompleto, double saldo);
    ~Cuenta();
    void setNumeroCuenta(std::string numeroCuenta);
    void setNombreCompleto(std::string nombreCompleto);
    std::string getNumeroCuenta();
    std::string getNombreCompleto();
    double getSaldo();
    void depositar(double cantidadDeposito);
    void retirar(double cantidadRetiro);
};

#endif //CUENTA_H
