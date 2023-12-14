#include<iostream>
#include<cstring>

using namespace std;

#include "ClienteArchivo.h"

//CONSTRUCTOR QUE GUARDA EL NOMBRE DEL ARCHIVO PARA USAR EN OTROS METODOS DE LA CLASE
ClienteArchivo::ClienteArchivo(const char * _nombre){
    strcpy(nombre, _nombre);
}

//GUARDA UN REGISTRO AL FINAL DE TODOS LOS REGISTROS EXISTENTES
bool ClienteArchivo::guardar(Cliente &reg){
    bool escribio = false;
    FILE * p = fopen(nombre, "ab");
    if (p == nullptr){
        return false;
    }
    escribio = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

//GUARDA UN REGISTRO Y REEMPLAZA SEGUN LA POSICION QUE RECIBA COMO PARAMETRO
bool ClienteArchivo::guardar(const Cliente &reg, int nroRegistro){
    bool escribio;
    FILE * p = fopen(nombre, "rb+");
    if (p == nullptr){
        return false;
    }
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    escribio = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return escribio;
}

//RECIBE EL ID DE CLIENTE, QUE PREVIAMENTE SE VERIFICO QUE EXISTA, LUEGO OFRECE LAS OPCIONES A MODIFICAR
bool ClienteArchivo::modificar(int ID){
    Cliente reg;
    FILE * p = fopen(nombre, "rb");
    if (p == nullptr){
        cout << "Error de lectura de archivo al modificar." << endl;
        system("pause");
        system("cls");
        return false;
    }
    return true;
}

//BUSCA EL ID DEL CLIENTE Y SI LO ENCUENTRA DEVUELVE SU POSICION EN EL ARCHIVO
int ClienteArchivo::buscarPorID(int ID){
    FILE * p = fopen(nombre, "rb");
    if (p == nullptr){
        return -1;
    }
    int i = 0;
    Cliente reg;
    while(fread(&reg, sizeof(Cliente), 1, p)){
        if(reg.getIdCliente() == ID){
        fclose(p);
        return i;
        }
        i++;
    }
    fclose(p);
    return -1;
}

//CUENTA LA CANTIDAD DE CLIENTES EN EL ARCHIVO
int ClienteArchivo::contarRegistros(){
    FILE * p = fopen(nombre, "rb");
    if (p == nullptr){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes / sizeof(Cliente);
}

//RECIBE COMO PARAMETRO LA POSICION EN LA QUE SE ENCUENTRA UN OBJETO DENTRO DEL ARCHIVO, SI LO UBICA DEVUELVE ESE OBJETO COMO VALOR
Cliente ClienteArchivo::leer(int nroRegistro){
    Cliente reg;
    FILE * p = fopen(nombre, "rb");
    if (p == nullptr){
        reg.setEstado(0);
        return reg;
    }
    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    fread(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return reg;
}
