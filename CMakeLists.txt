cmake_minimum_required(VERSION 3.30)
project(gestion_cuentas)

set(CMAKE_CXX_STANDARD 20)

add_executable(gestion_cuentas main.cpp Banco.h Banco.cpp Cuenta.h Cuenta.cpp)
