#ifndef PRODUCTOS_H
#define PRODUCTOS_H

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

void registrarProducto();
void buscarProducto();
void actualizarProducto();
void eliminarProducto();
void listarProductos();

#endif // PRODUCTOS_H
