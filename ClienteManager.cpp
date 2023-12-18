#include<iostream>
using namespace std;

#include "ClienteManager.h"

//CARGA DE CLIENTE CON TODOS SUS DATOS
void ClienteManager::cargar(){
    int _idCliente;
    char _nombreApellido[30];
    Direccion _direccion;
    char _telefono[30];

    bool aux = true;

    while (aux){
        system("cls");
        cout << "INGRESE EL ID DEL CLIENTE: ";
        cin >> _idCliente;

        if (_idCliente <= 0){
            system("cls");
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "NO SE PUEDE ASIGNAR UN NUMERO DE ID NEGATIVO A UN CLIENTE. INGRESE OTRO" << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");

            aux = true;
        }
        else{
            aux = false;
        }

    }

    while(buscar(_idCliente) != -1){
        system("cls");
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "EL ID INGRESADO CORRESPONDE A OTRO CLIENTE. INGRESE OTRO" << endl;
        rlutil::setColor(rlutil::WHITE);

        system("pause");
        system("cls");

        bool aux = true;

        while (aux){
            system("cls");
            cout << "INGRESE EL ID DEL CLIENTE: ";
            cin >> _idCliente;

            if (_idCliente <= 0){
                system("cls");
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "NO SE PUEDE ASIGNAR UN NUMERO DE ID NEGATIVO A UN CLIENTE. INGRESE OTRO" << endl;
                rlutil::setColor(rlutil::WHITE);
                system("pause");

                aux = true;
            }
            else{
                aux = false;
            }
        }

    }

    system ("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "INGRESO DE DATOS DEL CLIENTE #" << _idCliente << endl;
    cout << "--------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "NOMBRE Y APELLIDO: ";
    cargarCadena(_nombreApellido, 29);

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "INGRESO DE DATOS DEL CLIENTE #" << _idCliente << endl;
    cout << "--------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "DIRECCION" << endl;
    _direccion.cargar();

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "INGRESO DE DATOS DEL CLIENTE #" << _idCliente << endl;
    cout << "--------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "TELEFONO: ";
    cin >> _telefono;

    Cliente reg;

    reg.setIdCliente(_idCliente);
    reg.setNombreApellido(_nombreApellido);
    reg.setDireccion(_direccion);
    reg.setTelefono(_telefono);
    reg.setEstado(true);

    bool ok = archivo.guardar(reg);

    system("cls");

    if (ok){
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "EL CLIENTE SE REGISTRO EXITOSAMENTE" << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout << "EL CLIENTE NO SE REGISTRO CORRECTAMENTE" << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    cout << endl;
    system("pause");

}

//MUESTRA AL CLIENTE CON TODOS SUS DATOS
void ClienteManager::mostrar(Cliente reg){

    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "CLIENTE #" << reg.getIdCliente() << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "NOMBRE Y APELLIDO: ";
    rlutil::setColor(rlutil::WHITE);
    cout << reg.getNombreApellido() << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "DIRECCION: ";
    rlutil::setColor(rlutil::WHITE);
    cout << reg.getDireccion().getCalle() << " " << reg.getDireccion().getAltura() << ", " << reg.getDireccion().getLocalidad() << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "TELEFONO: ";
    rlutil::setColor(rlutil::WHITE);
    cout << reg.getTelefono() << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "---------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

//BAJA LOGICA DE UN CLIENTE (SETEA SU ESTADO A FALSE)
void ClienteManager::eliminar(){

    int id, posicion;

    cout << "INGRESE EL ID DEL CLIENTE QUE QUIERE ELIMINAR: ";
    cin >> id;

    posicion = archivo.buscarPorID(id);

    system("cls");

    if (posicion >= 0){
        Cliente aux = archivo.leer(posicion);
        rlutil::setColor(rlutil::YELLOW);
        cout << "CLIENTE A ELIMINAR" << endl;
        cout << "------------------" << endl;
        rlutil::setColor(rlutil::WHITE);
        mostrar(aux);

        cout << endl;

        char confirmacion;
        rlutil::setColor(rlutil::YELLOW);
        cout << "ESTA SEGURO QUE QUIERE ELIMINAR AL CLIENTE?" << endl;
        cout << "S/N: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> confirmacion;

        system("cls");

        if (confirmacion == 'S' || confirmacion == 's'){
            aux.setEstado(false);
            archivo.guardar(aux, posicion);
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "EL CLIENTE SE DIO DE BAJA CORRECTAMENTE" << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
        }
        else{
            rlutil::setColor(rlutil::YELLOW);
            cout << "REGISTRO NO ELIMINADO. VOLVIENDO AL MENU" << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
        }
    }
    else{
        rlutil::setColor(rlutil::RED);
        cout << "EL ID " << id << " NO EXISTE" << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
    }

}

//LISTA TODOS LOS CLIENTES ACTIVOS
void ClienteManager::listarTodos(){

    int cantidadRegistros = archivo.contarRegistros();
    Cliente obj;
    rlutil::setColor(rlutil::YELLOW);
    cout << "*********************************" << endl;
    cout << "*                               *" << endl;
    cout << "*  LISTADO DE CLIENTES ACTIVOS  *" << endl;
    cout << "*                               *" << endl;
    cout << "*********************************" << endl;
    rlutil::setColor(rlutil::WHITE);

    for(int i = 0; i < cantidadRegistros; i++){
        obj = archivo.leer(i);
        if(obj.getEstado()){
            mostrar(obj);
        }
    }

    system("pause");
}

//RECIBE COMO PARAMETRO EL ID DEL CLIENTE, SI LO ENCUENTRA, DEVUELVE LA POSICION DEL MISMO. SI NO LO ENCUENTRA DEVUELVE -1
int ClienteManager::buscar(int idCliente){

    int cantidadRegistros = archivo.contarRegistros();

    for(int i = 0; i < cantidadRegistros; i++){
        Cliente reg = archivo.leer(i);
        if (reg.getIdCliente() == idCliente){
            return i;
        }
    }

    return -1;
}

//PIDE UN ID DE CLIENTE Y LO MUESTRA
void ClienteManager::listarPorID(){

    int id, posicion;
    cout << "INGRESE EL ID DEL CLIENTE A LISTAR: ";
    cin >> id;

    system("cls");

    posicion = archivo.buscarPorID(id);

    if (posicion >= 0){
        Cliente aux = archivo.leer(posicion);
        mostrar(aux);
    }
    else{
        rlutil::setColor(rlutil::LIGHTRED);
        cout <<  "NO SE ENCONTRO EL ID " << id << " EN LA BASE DE DATOS" << endl << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    system("pause");
}


void ClienteManager::editar(){


}


bool ClienteManager::opcionesParaModificar(int idCLiente){


}


bool ClienteManager::modificarNombreApellido(int posicion){


}


bool ClienteManager::modificarCalle(int posicion){


}


bool ClienteManager::modificarAltura(int posicion){


}


bool ClienteManager::modificarLocalidad(int posicion){


}


bool ClienteManager::modificarTelefono(int posicion){


}
