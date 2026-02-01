#include "equipos.h"
#include "productos.h"
#include "utilidades.h"
#include <iostream>

using namespace std;

int main() {
    int opcion;

    while (true) {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int opcionEquipo;
                while (true) {
                    mostrarMenuEquipo();
                    cin >> opcionEquipo;

                    switch (opcionEquipo) {
                        case 1:
                            registrarEquipo();
                            break;
                        case 2:
                            buscarEquipo();
                            break;
                        case 3:
                            actualizarEquipo();
                            break;
                        case 4:
                            eliminarEquipo();
                            break;
                        case 5:
                            listarEquipos();
                            break;
                        case 6:
                            // Ordenar equipos (no implementado)
                            break;
                        case 7:
                            goto salirEquipo;
                        default:
                            cout << "Opción inválida" << endl;
                    }
                }
                salirEquipo:;
                break;
            }
            case 2: {
                int opcionProducto;
                while (true) {
                    mostrarMenuProducto();
                    cin >> opcionProducto;

                    switch (opcionProducto) {
                        case 1:
                            registrarProducto();
                            break;
                        case 2:
                            buscarProducto();
                            break;
                        case 3:
                            actualizarProducto();
                            break;
                        case 4:
                            eliminarProducto();
                            break;
                        case 5:
                            listarProductos();
                            break;
                        case 6:
                            // Ordenar productos (no implementado)
                            break;
                        case 7:
                            goto salirProducto;
                        default:
                            cout << "Opción inválida" << endl;
                    }
                }
                salirProducto:;
                break;
            }
            case 3:
                return 0;
            default:
                cout << "Opción inválida" << endl;
        }
    }

    return 0;
}

