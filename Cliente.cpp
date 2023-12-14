#include<iostream>
#include<cstring>

using namespace std;

#include "CargarCadena.h"
#include "Cliente.h"


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

void Cliente::cargar(){
    cout << "ID DE CLIENTE NUEVO: ";
    cin >> idCliente;
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "CLIENTE #" << idCliente << endl;
    cout << "-----------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "NOMBRE Y APELLIDO: ";
    cargarCadena(nombreApellido, 49);
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "CLIENTE #" << idCliente << endl;
    cout << "-----------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "DIRECCION" << endl << endl;
    direccion.cargar();
    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "CLIENTE #" << idCliente << endl;
    cout << "-----------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "TELEFONO: ";
    cargarCadena(telefono, 29);
    system("cls");
    estado = true;
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "CLIENTE #" << idCliente << " CARGADO EXITOSAMENTE" << endl << endl;
    rlutil::setColor(rlutil::WHITE);
}
void Cliente::mostrar(){
    rlutil::setColor(rlutil::YELLOW);
    cout << "CLIENTE #" << idCliente << endl;
    cout << "-----------" << endl << endl;
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "NOMBRE Y APELLIDO: ";
    rlutil::setColor(rlutil::WHITE);
    cout << nombreApellido << endl << endl;
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "DIRECCION" << endl;
    rlutil::setColor(rlutil::WHITE);
    direccion.mostrar();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl << "TELEFONO: ";
    rlutil::setColor(rlutil::WHITE);
    cout << telefono << endl;
    if (!estado){
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "CLIENTE INACTIVO" << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    cout << endl << "-----------------------------" << endl;
}
