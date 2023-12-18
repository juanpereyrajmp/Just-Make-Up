#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include "ClienteArchivo.h"

class ClienteManager{
private:
    ClienteArchivo archivo = ClienteArchivo("Clientes.dat");

public:
    void cargar();
    void mostrar(Cliente reg);
    void eliminar();
    void listarTodos();
    int buscar(int idCliente);
    void listarPorID();
    void editar();
    bool opcionesParaModificar(int idCliente);
    bool modificarNombreApellido(int posicion);
    bool modificarCalle(int posicion);
    bool modificarAltura(int posicion);
    bool modificarLocalidad(int posicion);
    bool modificarTelefono(int posicion);
};

#endif // CLIENTEMANAGER_H
