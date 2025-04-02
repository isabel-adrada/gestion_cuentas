/** Actividad 10
 * Grupo 1
 */

#include <iostream>
#include <string>
#include <vector>
#include "Banco.h"
#include "Cuenta.h"

void mostrarMenu() {
    std::cout << std::endl << "=== Gestión de Cuentas ===" << std::endl;
    std::cout << "1. Agregar nueva cuenta" << std::endl;
    std::cout << "2. Listar cuentas existentes" << std::endl;
    std::cout << "3. Buscar cuenta" << std::endl;
    std::cout << "4. Salir" << std::endl << std::endl;
    std::cout << "Seleccione una opción: ";
}

void operaciones(Cuenta cuentaEncontrada) {
    int operacion;
    std::cout << "Seleccione una operación: " << std::endl;
    std::cout << "1. Depositar" << std::endl;
    std::cout << "2. Retirar " << std::endl;
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
}

void infoCuenta(Cuenta cuenta) {
    std::cout << "Número de cuenta: " << cuenta.getNumeroCuenta() << std::endl
        << "Titular: " << cuenta.getNombreCompleto() << std::endl
        << "Saldo: " << cuenta.getSaldo() << std::endl;
}

int main() {
    Banco banco;
    int opcion;
    std::vector<int> numerosCuentas;
    for (int i = 0; i < 1001; i++) {
        numerosCuentas.push_back(i);
    }
    std::cout << std::endl << "====== " << banco.getNombre() << " ======" << std::endl;
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
            std::cout << std::endl << "Ingrese el nombre completo del titular: ";
            std::cin.ignore(); // Limpiar el buffer
            std::getline(std::cin, nombreCompleto);
            std::cout << "Ingrese el saldo inicial: ";
            std::cin >> saldoInicial;
            Cuenta cuenta(numeroCuenta, nombreCompleto, saldoInicial);
            banco.registrarCuenta(cuenta);
            std::cout << std::endl << "Cuenta creada exitosamente con el número de cuenta " << numeroCuenta << "." << std::endl;
            break;
        }
        case 2: {
            // Listar cuentas existentes
            std::vector<Cuenta> cuentas = banco.getCuentas();
                if (cuentas.empty()) {
                    std::cout << std::endl << "No hay cuentas registradas en el banco " << std::endl;
                } else {
                    std::cout << std::endl << "=== Cuentas existentes ===" << std::endl;
                    for (Cuenta cuenta : cuentas) {
                        std::cout << std::endl;
                        infoCuenta(cuenta);
                    }
                }
            break;
        }
        case 3: {
            // Buscar cuenta
            int opcionBuscar;
            std::cout << std::endl << "Seleccione una opción de búsqueda:  " << std::endl;
            std::cout << "1. Número de cuenta" << std::endl;
            std::cout << "2. Titular de la cuenta" << std::endl;
            std::cin >> opcionBuscar;
            if (opcionBuscar == 1) {
                std::string numeroBuscado;
                std::cout << "Ingrese el número de cuenta: ";
                std::cin.ignore(); // Limpiar el buffer
                std::getline(std::cin, numeroBuscado);
                Cuenta cuentaEncontrada = banco.getCuentaNumero(numeroBuscado);
                if (cuentaEncontrada.getNumeroCuenta() != "") {
                    std::cout << std::endl << "Cuenta encontrada: " << std::endl;
                    infoCuenta(cuentaEncontrada);
                    std::cout << std::endl;
                    operaciones(cuentaEncontrada);
                } else {
                    std::cout << "No se encontró ninguna cuenta con el número de cuenta proporcionado." << std::endl;
                }
            } else if (opcionBuscar == 2) {
                std::string nombreBuscado;
                std::cout << "Ingrese el nombre del titular a buscar: ";
                std::cin.ignore(); // Limpiar el buffer
                std::getline(std::cin, nombreBuscado);
                std::vector<Cuenta> coincidencias = {};
                for (Cuenta cuenta : banco.getCuentas()) {
                    if (cuenta.getNombreCompleto() == nombreBuscado) {
                        coincidencias.push_back(cuenta);
                    }
                }
                if (coincidencias.size() > 1) {
                    std::cout << std::endl << "Cuentas encontradas: " << std::endl;
                    for (Cuenta cuenta : coincidencias) {
                        infoCuenta(cuenta);
                        std::cout << std::endl;
                    }
                    std::cout << "Para realizar una operación con una de estas cuentas, realice la búsqueda por número de cuenta." << std::endl;
                } else if (coincidencias.size() == 1) {
                    std::cout << std::endl << "Cuenta encontrada: " << std::endl;
                    infoCuenta(coincidencias.at(0));
                    std::cout << std::endl;
                    operaciones(coincidencias.at(0));
                } else{
                    std::cout << "No se encontró ninguna cuenta con el número de cuenta proporcionado." << std::endl;
                }
            }
            break;
        }
        case 4: {
            std::cout << std::endl << "Saliendo del sistema." << std::endl;
            break;
        }
        default:
            std::cout << "Opción no válida. Intente de nuevo." << std::endl;
            break;
        }
    } while (opcion != 4);
    return 0;
}

