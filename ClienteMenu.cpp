#include<iostream>
using namespace std;

#include "ClienteMenu.h"

void ClienteMenu::iniciar(){
    int opc;
    while(true){
        system("cls");
        cout << "**************************" << endl;
        cout << "******** CLIENTES ********" << endl;
        cout << "**************************" << endl;
        cout << "1 - NUEVO CLIENTE" << endl;
        cout << "2 - MODIFICAR CLIENTE" << endl;
        cout << "3 - LISTAR CLIENTES" << endl;
        cout << "4 - ANULAR CLIENTE" << endl;
        cout << "**************************" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
        case 1:
            clienteManager.cargar();
            break;
        case 2:

            break;
        case 3:
            clienteListarMenu.iniciar();
            break;
        case 4:
            clienteManager.eliminar();
            break;
        case 0:
            return;
            break;
        default:
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "OPCION INCORRECTA. SELECCIONE NUEVAMENTE" << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            break;
        }
    }
}
