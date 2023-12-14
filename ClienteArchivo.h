#ifndef CLIENTEARCHIVO_H
#define CLIENTEARCHIVO_H

#include "rlutil.h"
#include "Cliente.h"

class ClienteArchivo{
private:
    char nombre[30];

public:
    ClienteArchivo(const char * _nombre);
    bool guardar(Cliente &reg);
    bool guardar(const Cliente &reg, int nroRegistro);
    bool modificar(int ID);
    int buscarPorID(int ID);
    int contarRegistros();
    Cliente leer(int nroRegistro);
};

#endif // CLIENTEARCHIVO_H
