#include<iostream>
#include<cstring>

using namespace std;

#include "Direccion.h"

void Direccion::setCalle(const char *calle){
    strcpy(_calle,calle);
}
void Direccion::setAltura(int altura){
    _altura = altura;
}
void Direccion::setLocalidad(const char *localidad){
    strcpy(_localidad,localidad);
}

const char *Direccion::getCalle(){
    return _calle;
}
int Direccion::getAltura(){
    return _altura;
}
const char *Direccion::getLocalidad(){
    return _localidad;
}

void Direccion::cargar(){
    cout << "Calle: ";
    cargarCadena(_calle,29);
    cout << "Altura: ";
    cin >> _altura;
    cout << "Localidad: ";
    cargarCadena(_localidad,29);
}
void Direccion::mostrar(){
    rlutil::setColor(rlutil::CYAN);
    cout << "Calle: ";
    rlutil::setColor(rlutil::WHITE);
    cout << _calle << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << "Altura: ";
    rlutil::setColor(rlutil::WHITE);
    cout << _altura << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << "Localidad: ";
    rlutil::setColor(rlutil::WHITE);
    cout << _localidad << endl;
}

Direccion::Direccion(){
    setCalle("");
    setAltura(0);
    setLocalidad("");
}

