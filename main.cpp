/** Actividad 10
 * Grupo 1
 */

#include <iostream>
#include <string>
#include <vector>
#include "Banco.h"
#include "Cuenta.h"

void mostrarMenu() {
    std::cout << "=== Gestión de Cuentas ===" << std::endl;
    std::cout << "1. Agregar nueva cuenta" << std::endl;
    std::cout << "2. Listar cuentas existentes" << std::endl;
    std::cout << "3. Buscar cuenta" << std::endl;
    std::cout << "4. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    Banco banco;
    int opcion;
    std::vector<int> numerosCuentas;
    for (int i = 0; i < 1001; i++) {
        numerosCuentas.push_back(i);
    }
    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
            case 1: { // Agregar nueva cuenta
                auto num = numerosCuentas.at(0);
                std::string numeroCuenta = std::to_string(num);
                numerosCuentas.erase(numerosCuentas.begin());
                std::string nombreCompleto;
                double saldoInicial;

                std::cout << "Ingrese el nombre completo del titular: ";
                std::cin.ignore(); // Limpiar el buffer
                std::getline(std::cin, nombreCompleto);
                std::cout << "Ingrese el saldo inicial: ";
                std::cin >> saldoInicial;
                Cuenta cuenta(numeroCuenta, nombreCompleto, saldoInicial);
                banco.registrarCuenta(cuenta);
                std::cout << "Cuenta creada exitosamente." << std::endl;
                break;
            }
            case 2: {
                // Listar cuentas existentes
                std::vector<Cuenta> cuentas = banco.getCuentas();
                std::cout << "=== Cuentas existentes ===" << std::endl;
                for (Cuenta cuenta : cuentas) {
                    std::cout << "Número de cuenta: " << cuenta.getNumeroCuenta()
                              << ", Titular: " << cuenta.getNombreCompleto()
                              << ", Saldo: " << cuenta.getSaldo() << std::endl;
                }
                break;
            }
            case 3: {
                // Buscar cuenta
                std::string nombreBuscado;
                std::cout << "Ingrese el nombre del titular a buscar: ";
                std::cin.ignore(); // Limpiar el buffer
                std::getline(std::cin, nombreBuscado);

                Cuenta cuentaEncontrada = banco.getCuentaNombre(nombreBuscado);
                if (cuentaEncontrada.getNumeroCuenta() != "") {
                    std::cout << "Cuenta encontrada: " << std::endl;
                    std::cout << "Número de cuenta: " << cuentaEncontrada.getNumeroCuenta()
                              << ", Titular: " << cuentaEncontrada.getNombreCompleto()
                              << ", Saldo: " << cuentaEncontrada.getSaldo() << std::endl;

                    // Opción de depositar o retirar
                    int operacion;
                    std::cout << "Seleccione una operación: 1. Depositar 2. Retirar: ";
                    std::cin >> operacion;

                    if (operacion == 1) {
                        double cantidadDeposito;
                        std::cout << "Ingrese la cantidad a depositar: ";
                        std::cin >> cantidadDeposito;
                        cuentaEncontrada.depositar(cantidadDeposito);
                    } else if (operacion == 2) {
                        double cantidadRetiro;
                        std::cout << "Ingrese la cantidad a retirar: ";
                        std::cin >> cantidadRetiro;
                        cuentaEncontrada.retirar(cantidadRetiro);
                    }
                } else {
                    std::cout << "No se encontró ninguna cuenta con el titular proporcionado." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Saliendo del sistema." << std::endl;
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}

