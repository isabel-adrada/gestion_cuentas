/** Actividad 10
 * Grupo 1
 */

#include <iostream>
#include <string>
#include <vector>
#include "Banco.h"
#include "Cuenta.h"

//Generación automática de los números de cuenta
int numerosCuentas = 1000000;

//Menus recurrentes
void mostrarMenu() {
    std::cout << std::endl << "=== Gestión de Cuentas ===" << std::endl;
    std::cout << "1. Agregar nueva cuenta" << std::endl;
    std::cout << "2. Listar cuentas existentes" << std::endl;
    std::cout << "3. Buscar cuenta" << std::endl;
    std::cout << "4. Salir del programa" << std::endl << std::endl;
    std::cout << "Seleccione una opción: ";
}

void menuBuscar() {
    std::cout << std::endl << "=== Opción de búsqueda ===" << std::endl;
    std::cout << "1. Número de cuenta" << std::endl;
    std::cout << "2. Titular de la cuenta" << std::endl;
    std::cout << "3. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opción:  ";
}

void menuOperaciones() {
    std::cout << "=== Operación de Cuentas ===" << std::endl;
    std::cout << "1. Depositar" << std::endl;
    std::cout << "2. Retirar" << std::endl;
    std::cout << "3. Modificar información de la cuenta" << std::endl;
    std::cout << "4. Eliiminar cuenta " << std::endl;
    std::cout << "5. Regresar" << std::endl << std::endl;
    std::cout << "Seleccione una opción: ";
}

void operaciones(Cuenta* cuentaEncontrada, std::map<std::string, Cuenta*>* cuentas) {
    int operacion;
    do {
        menuOperaciones();
        std::cin >> operacion;

        switch (operacion) {
            case 1: {
                double cantidadDeposito;
                std::cout << std::endl << "Ingrese la cantidad a depositar: ";
                std::cin >> cantidadDeposito;
                cuentaEncontrada -> depositar(cantidadDeposito);
                std::cout << std::endl;
                break;
            }
            case 2 : {
                double cantidadRetiro;
                std::cout << std::endl << "Ingrese la cantidad a retirar: ";
                std::cin >> cantidadRetiro;
                cuentaEncontrada -> retirar(cantidadRetiro);
                std::cout << std::endl;
                break;
            }
            case 3 : {
                std::string nuevoNombre;
                std::cout << std::endl << "El banco solo permite la modificación del nombre del titular de la cuenta." << std:: endl;
                std::cout << "Ingrese el nuevo nombre del titular de la cuenta: ";
                std::cin.ignore(); // Limpiar el buffer
                std::getline(std::cin, nuevoNombre);
                cuentaEncontrada -> setNombreCompleto(nuevoNombre);
                std::cout << std::endl << "El nombre del titular de la cuenta número " << cuentaEncontrada -> getNumeroCuenta()
                    << " ha sido actializado." << std::endl << std::endl;
                break;
            }
            case 4 : {
                if (cuentaEncontrada -> getSaldo() > 0 ) {
                    std::cout << std::endl << "La cuenta tiene un saldo de "
                    << cuentaEncontrada -> getSaldo() << std::endl;
                    std::cout << "Debe retirar la totalidad antes de proceder con la eliminación de la cuenta." << std::endl << std::endl;
                    break;
                }
                cuentas -> erase(cuentaEncontrada -> getNumeroCuenta());
                cuentaEncontrada -> ~Cuenta();
                std::cout << std::endl << "Cuenta eliminada exitosamente." << std::endl;
                operacion = 5;
                break;
            }
            case 5 : {
                break;
            }
            default: {
                std::cout << std::endl << "Opcion no valida. Intente de nuevo." << std::endl;
                break;
            }
        }

    } while (operacion != 5);
}

void infoCuenta(Cuenta* cuenta) {
    std::cout << "Número de cuenta: " << cuenta -> getNumeroCuenta() << std::endl
        << "Titular: " << cuenta -> getNombreCompleto() << std::endl
        << "Saldo: " << cuenta -> getSaldo() << std::endl;
}

int main() {
    Banco *banco = new Banco();
    std::map<std::string, Cuenta*>* cuentas = banco -> getCuentas();
    std::map<std::string, Cuenta*>::iterator it;
    int opcion;
    std::cout << std::endl << "====== " << banco -> getNombre() << " ======" << std::endl;
    do {
        mostrarMenu();
        std::cin >> opcion;
        switch (opcion) {
        case 1: { // Agregar nueva cuenta
            std::string numeroCuenta = std::to_string(numerosCuentas);
            numerosCuentas++;
            std::string nombreCompleto;
            double saldoInicial;
            std::cout << std::endl << "Ingrese el nombre completo del titular: ";
            std::cin.ignore(); // Limpiar el buffer
            std::getline(std::cin, nombreCompleto);
            std::cout << "Ingrese el saldo inicial: ";
            std::cin >> saldoInicial;

            Cuenta *cuenta = new Cuenta(numeroCuenta, nombreCompleto, saldoInicial);
            banco -> registrarCuenta(cuenta);
            std::cout << std::endl << "Cuenta creada exitosamente con el número de cuenta " << numeroCuenta << "." << std::endl;
            break;
        }
        case 2: { // Listar cuentas existentes
            if (cuentas -> empty()) {
                std::cout << std::endl << "No hay cuentas registradas en el banco " << std::endl;
            } else {
                std::cout << std::endl << "=== Cuentas existentes ===" << std::endl;
                for (it = cuentas -> begin(); it != cuentas -> end(); ++it) {
                    std::cout << std::endl;
                    infoCuenta(it -> second);
                }
            }
            break;
        }
        case 3: { // Buscar cuenta
            int opcionBuscar;
            menuBuscar();
            std::cin >> opcionBuscar;
            do {
                switch (opcionBuscar) {
                    case 1 : {
                        std::string numeroBuscado;
                        std::cout << "Ingrese el número de cuenta: ";
                        std::cin.ignore(); // Limpiar el buffer
                        std::getline(std::cin, numeroBuscado);
                        Cuenta* cuentaEncontrada = banco -> getCuentaNumero(numeroBuscado);
                        if (cuentaEncontrada != nullptr) {
                            std::cout << std::endl << "Cuenta encontrada: " << std::endl;
                            infoCuenta(cuentaEncontrada);
                            std::cout << std::endl;
                            operaciones(cuentaEncontrada, cuentas);
                        } else {
                            std::cout << "No se encontró ninguna cuenta con el número de cuenta proporcionado." << std::endl;
                        }
                        break;
                    }
                    case 2 : {
                        std::string nombreBuscado;
                        std::cout << "Ingrese el nombre del titular a buscar: ";
                        std::cin.ignore(); // Limpiar el buffer
                        std::getline(std::cin, nombreBuscado);
                        std::map<std::string, Cuenta*> coincidencias = {};
                        for (it = cuentas -> begin(); it != cuentas -> end(); ++it) {
                            if ((it -> second)->getNombreCompleto() == nombreBuscado) {
                                coincidencias.insert({it -> second -> getNumeroCuenta(), it -> second});
                            }
                        }
                        if (coincidencias.size() > 1) {
                            std::cout << std::endl << "Cuentas encontradas: " << std::endl << std::endl;
                            for (it = cuentas -> begin(); it != cuentas -> end(); ++it) {
                                infoCuenta(it -> second);
                                std::cout << std::endl;
                            }
                            std::cout << "Para realizar una operación con una de estas cuentas, realice la búsqueda por número de cuenta." << std::endl;
                        } else if (coincidencias.size() == 1) {
                            std::cout << std::endl << "Cuenta encontrada: " << std::endl << std::endl;
                            Cuenta* coincidencia;
                            for (it = cuentas -> begin(); it != cuentas -> end(); ++it) {
                            coincidencia = it -> second;
                                infoCuenta(coincidencia);
                            }
                            std::cout << std::endl;
                            operaciones(coincidencia, cuentas);
                        } else {
                            std::cout << "No se encontró ninguna cuenta con el número de cuenta proporcionado." << std::endl;
                        }
                        break;
                    }
                    case 3 : {
                        break;
                    }
                    default : {
                        std::cout << "Opción no válida. Intente de nuevo." << std::endl;
                        break;
                    }
                }

            } while (opcion != 3);
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

