#ifndef EQUIPOS_H
#define EQUIPOS_H

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

void registrarEquipo();
void buscarEquipo();
void actualizarEquipo();
void eliminarEquipo();
void listarEquipos();

#endif // EQUIPOS_H
