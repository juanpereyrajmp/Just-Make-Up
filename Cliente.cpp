#include<iostream>
#include<cstring>

using namespace std;

#include "CargarCadena.h"
#include "Cliente.h"

//GETTERS
int Cliente::getIdCliente(){
    return idCliente;
}
const char * Cliente::getNombreApellido(){
    return nombreApellido;
}
Direccion Cliente::getDireccion(){
    return direccion;
}
const char * Cliente::getTelefono(){
    return telefono;
}
bool Cliente::getEstado(){
    return estado;
}

//SETTERS
void Cliente::setIdCliente(int _idCliente){
    idCliente = _idCliente;
}
void Cliente::setNombreApellido(const char * _nombreApellido){
    strcpy(nombreApellido, _nombreApellido);
}
void Cliente::setDireccion(Direccion _direccion){
    direccion = _direccion;
}
void Cliente::setTelefono(const char * _telefono){
    strcpy(telefono, _telefono);
}
void Cliente::setEstado(bool _estado){
    estado = _estado;
}
