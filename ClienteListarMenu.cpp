#include<iostream>
using namespace std;

#include "ClienteListarMenu.h"

void ClienteListarMenu::iniciar(){
    int opc;
    while(true){
        system("cls");
        cout << "***************************" << endl;
        cout << "***** LISTAR CLIENTES *****" << endl;
        cout << "***************************" << endl;
        cout << "1 - LISTAR TODOS" << endl;
        cout << "2 - LISTAR POR ID" << endl;
        cout << "***************************" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
        case 1:
            clienteManager.listarTodos();
            break;
        case 2:
            clienteManager.listarPorID();
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
