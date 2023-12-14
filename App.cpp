#include<iostream>

using namespace std;

#include "App.h"

void App::run(){

    int opc;
    while(true){
        system("cls");
        cout << "**************************" << endl;
        cout << "********** MENU **********" << endl;
        cout << "**************************" << endl;
        cout << "1 - Trabajos" << endl;
        cout << "2 - Servicios" << endl;
        cout << "3 - Clientes" << endl;
        cout << "**************************" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> opc;
        system("cls");
        switch(opc){
        case 1:

            break;
        case 2:

            break;
        case 3:

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
