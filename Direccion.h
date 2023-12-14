#ifndef DIRECCION_H
#define DIRECCION_H
#pragma once

#include<cstring>

#include "rlutil.h"
#include "CargarCadena.h"


class Direccion{
public:
    void setCalle(const char *calle);
    void setAltura(int altura);
    void setLocalidad(const char *localidad);

    const char *getCalle();
    int getAltura();
    const char *getLocalidad();

    void cargar();
    void mostrar();

    Direccion();

private:
    char _calle[30];
    int _altura;
    char _localidad[30];
};


#endif // DIRECCION_H
