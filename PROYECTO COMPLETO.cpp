#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Estructura Equipo de Desarrollo
struct Equipo {
    int id;
    string nombre;
    string lider;
    int numIntegrantes;
    string lenguajes;
    string herramientas;
    string proyectos;
    string fechaCreacion;
    string estado;
    string ubicacion;
};

// Estructura Producto de Software
struct Producto {
    int id;
    string nombre;
    string descripcion;
    string tipo;
    string lenguajes;
    string frameworks;
    string clientes;
    string fechaEntrega;
    string estado;
    string version;
};

// Menú principal
void mostrarMenuPrincipal() {
    cout << "Menú Principal" << endl;
    cout << "1. Gestión de Equipos de Desarrollo" << endl;
    cout << "2. Gestión de Productos de Software" << endl;
    cout << "3. Salir" << endl;
}

// Menú secundario de Equipos de Desarrollo
void mostrarMenuEquipo() {
    cout << "Menú de Equipos de Desarrollo" << endl;
    cout << "1. Registrar Equipo" << endl;
    cout << "2. Buscar Equipo" << endl;
    cout << "3. Actualizar Equipo" << endl;
    cout << "4. Eliminar Equipo" << endl;
    cout << "5. Listar Equipos" << endl;
    cout << "6. Ordenar Equipos" << endl;
    cout << "7. Volver al Menú Principal" << endl;
}

// Menú secundario de Productos de Software
void mostrarMenuProducto() {
    cout << "Menú de Productos de Software" << endl;
    cout << "1. Registrar Producto" << endl;
    cout << "2. Buscar Producto" << endl;
    cout << "3. Actualizar Producto" << endl;
    cout << "4. Eliminar Producto" << endl;
    cout << "5. Listar Productos" << endl;
    cout << "6. Ordenar Productos" << endl;
    cout << "7. Volver al Menú Principal" << endl;
}

// Registrar un equipo
void registrarEquipo() {
    ofstream archivo("equipos.csv", ios::app);
    Equipo equipo;
    cout << "Ingrese el ID del equipo: ";
    cin >> equipo.id;
    cout << "Ingrese el nombre del equipo: ";
    cin >> equipo.nombre;
    cout << "Ingrese el líder del equipo: ";
    cin >> equipo.lider;
    cout << "Ingrese el número de integrantes: ";
    cin >> equipo.numIntegrantes;
    cout << "Ingrese los lenguajes de programación: ";
    cin >> equipo.lenguajes;
    cout << "Ingrese las herramientas utilizadas: ";
    cin >> equipo.herramientas;
    cout << "Ingrese los proyectos asignados: ";
    cin >> equipo.proyectos;
    cout << "Ingrese la fecha de creación: ";
    cin >> equipo.fechaCreacion;
    cout << "Ingrese el estado (Activo/Inactivo): ";
    cin >> equipo.estado;
    cout << "Ingrese la ubicación: ";
    cin >> equipo.ubicacion;
    archivo << equipo.id << "," << equipo.nombre << "," << equipo.lider << "," << equipo.numIntegrantes << "," << equipo.lenguajes << "," << equipo.herramientas << "," << equipo.proyectos << "," << equipo.fechaCreacion << "," << equipo.estado << "," << equipo.ubicacion << endl;
    archivo.close();
    cout << "Equipo registrado con éxito." << endl;
}

// Buscar un equipo
void buscarEquipo() {
    ifstream archivo("equipos.csv");
    if (archivo.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del equipo a buscar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idEquipo;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                    if (idEquipo == id) {
                        cout << "Equipo encontrado:" << endl;
                        cout << "ID: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Nombre: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Lider: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Número de integrantes: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Lenguajes de programación: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Herramientas utilizadas: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Proyectos asignados: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Fecha de creación: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Estado: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Ubicación: " << campo << endl;
                        return;
                    }
                }
                i++;
            }
        }
        cout << "Equipo no encontrado." << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Actualizar un equipo
void actualizarEquipo() {
    ifstream archivo("equipos.csv");
    ofstream temp("temp.csv");
    if (archivo.is_open() && temp.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del equipo a actualizar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idEquipo;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                        Equipo equipo;
                        cout << "Ingrese el nuevo nombre del equipo: ";
                        cin >> equipo.nombre;
                        cout << "Ingrese el nuevo líder del equipo: ";
                        cin >> equipo.lider;
                        cout << "Ingrese el nuevo número de integrantes: ";
                        cin >> equipo.numIntegrantes;
                        cout << "Ingrese los nuevos lenguajes de programación: ";
                        cin >> equipo.lenguajes;
                        cout << "Ingrese las nuevas herramientas utilizadas: ";
                        cin >> equipo.herramientas;
                        cout << "Ingrese los nuevos proyectos asignados: ";
                        cin >> equipo.proyectos;
                        cout << "Ingrese la nueva fecha de creación: ";
                        cin >> equipo.fechaCreacion;
                        cout << "Ingrese el nuevo estado (Activo/Inactivo): ";
                        cin >> equipo.estado;
                        cout << "Ingrese la nueva ubicación: ";
                        cin >> equipo.ubicacion;
                        temp << id << "," << equipo.nombre << "," << equipo.lider << "," << equipo.numIntegrantes << "," << equipo.lenguajes << "," << equipo.herramientas << "," << equipo.proyectos << "," << equipo.fechaCreacion << "," << equipo.estado << "," << equipo.ubicacion << endl;
                        cout << "Equipo actualizado con éxito." << endl;
                    } else {
                        temp << linea << endl;
                    }
                }
                i++;
            }
        }
        archivo.close();
        temp.close();
        remove("equipos.csv");
        rename("temp.csv", "equipos.csv");
        cout << "No se pudo abrir el archivo." << endl;
    }

// Eliminar un equipo
void eliminarEquipo() {
    ifstream archivo("equipos.csv");
    ofstream temp("temp.csv");
    if (archivo.is_open() && temp.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del equipo a eliminar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idEquipo;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                    if (idEquipo != id) {
                        temp << linea << endl;
                    }
                }
                i++;
            }
        }
        archivo.close();
        temp.close();
        remove("equipos.csv");
        rename("temp.csv", "equipos.csv");
        cout << "Equipo eliminado con éxito." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Listar equipos
void listarEquipos() {
    ifstream archivo("equipos.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Registrar un producto
void registrarProducto() {
    ofstream archivo("productos.csv", ios::app);
    Producto producto;
    cout << "Ingrese el ID del producto: ";
    cin >> producto.id;
    cout << "Ingrese el nombre del producto: ";
    cin >> producto.nombre;
    cout << "Ingrese la descripción del producto: ";
    cin >> producto.descripcion;
    cout << "Ingrese el tipo de producto: ";
    cin >> producto.tipo;
    cout << "Ingrese los lenguajes utilizados: ";
    cin >> producto.lenguajes;
    cout << "Ingrese los frameworks utilizados: ";
    cin >> producto.frameworks;
    cout << "Ingrese los clientes: ";
    cin >> producto.clientes;
    cout << "Ingrese la fecha de entrega: ";
    cin >> producto.fechaEntrega;
    cout << "Ingrese el estado (En Desarrollo/Entregado): ";
    cin >> producto.estado;
    cout << "Ingrese la versión: ";
    cin >> producto.version;
    archivo << producto.id << "," << producto.nombre << "," << producto.descripcion << "," << producto.tipo << "," << producto.lenguajes << "," << producto.frameworks << "," << producto.clientes << "," << producto.fechaEntrega << "," << producto.estado << "," << producto.version << endl;
    archivo.close();
    cout << "Producto registrado con éxito." << endl;
}

// Buscar un producto
void buscarProducto() {
    ifstream archivo("productos.csv");
    if (archivo.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del producto a buscar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idProducto;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                    if (idProducto == id) {
                        cout << "Producto encontrado:" << endl;
                        cout << "ID: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Nombre: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Descripción: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Tipo: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Lenguajes: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Frameworks: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Clientes: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Fecha de entrega: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Estado: " << campo << endl;
                        i++;
                        getline(ss, campo, ',');
                        cout << "Versión: " << campo << endl;
                        return;
                    }
                }
                i++;
            }
        }
        cout << "Producto no encontrado." << endl;
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Actualizar un producto 
void actualizarProducto() {
    ifstream archivo("productos.csv");
    ofstream temp("temp.csv");
    if (archivo.is_open() && temp.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del producto a actualizar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idProducto;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                    if (idProducto == id) {
                        Producto producto;
                        cout << "Ingrese el nuevo nombre del producto: ";
                        cin >> producto.nombre;
                        cout << "Ingrese la nueva descripción del producto: ";
                        cin >> producto.descripcion;
                        cout << "Ingrese el nuevo tipo de producto: ";
                        cin >> producto.tipo;
                        cout << "Ingrese los nuevos lenguajes utilizados: ";
                        cin >> producto.lenguajes;
                        cout << "Ingrese los nuevos frameworks utilizados: ";
                        cin >> producto.frameworks;
                        cout << "Ingrese los nuevos clientes: ";
                        cin >> producto.clientes;
                        cout << "Ingrese la nueva fecha de entrega: ";
                        cin >> producto.fechaEntrega;
                        cout << "Ingrese el nuevo estado (En Desarrollo/Entregado): ";
                        cin >> producto.estado;
                        cout << "Ingrese la nueva versión: ";
                        cin >> producto.version;
                        temp << id << "," << producto.nombre << "," << producto.descripcion << "," << producto.tipo << "," << producto.lenguajes << "," << producto.frameworks << "," << producto.clientes << "," << producto.fechaEntrega << "," << producto.estado << "," << producto.version << endl;
                        cout << "Producto actualizado con éxito." << endl;
                    } else {
                        temp << linea << endl;
                    }
                }
                i++;
            }
        }
        archivo.close();
        temp.close();
        remove("productos.csv");
        rename("temp.csv", "productos.csv");
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Eliminar un producto 
void eliminarProducto() {
    ifstream archivo("productos.csv");
    ofstream temp("temp.csv");
    if (archivo.is_open() && temp.is_open()) {
        string linea;
        int id;
        cout << "Ingrese el ID del producto a eliminar: ";
        cin >> id;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string campo;
            int i = 0;
            int idProducto;
            while (getline(ss, campo, ',')) {
                if (i == 0) {
                    if (idProducto != id) {
                        temp << linea << endl;
                    }
                }
                i++;
            }
        }
        archivo.close();
        temp.close();
        remove("productos.csv");
        rename("temp.csv", "productos.csv");
        cout << "Producto eliminado con éxito." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Listar productos 
void listarProductos() {
    ifstream archivo("productos.csv");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

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
