#ifndef CLIENTE_H
#define CLIENTE_H
#include "Direccion.h"
#include "rlutil.h"

class Cliente{
private:
    int idCliente;
    char nombreApellido[50];
    Direccion direccion;
    char telefono[30];
    bool estado;

public:
    int getIdCliente();
    const char * getNombreApellido();
    Direccion getDireccion();
    const char * getTelefono();
    bool getEstado();

    void setIdCliente(int _idCliente);
    void setNombreApellido(const char * _nombreApellido);
    void setDireccion(Direccion _direccion);
    void setTelefono(const char * _telefono);
    void setEstado(bool _estado);
};

#endif // CLIENTE_H
