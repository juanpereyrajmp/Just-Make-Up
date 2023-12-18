#include<iostream>

using namespace std;

#include "App.h"

void App::run(){

    int opc;
    while(true){
        system("cls");
        cout << "******************************" << endl;
        cout << "*                            *" << endl;
        cout << "*            MENU            *" << endl;
        cout << "*                            *" << endl;
        cout << "******************************" << endl;
        cout << "*                            *" << endl;
        cout << "* 1 - TRABAJOS               *" << endl;
        cout << "*                            *" << endl;
        cout << "* 2 - SERVICIOS              *" << endl;
        cout << "*                            *" << endl;
        cout << "* 3 - CLIENTES               *" << endl;
        cout << "*                            *" << endl;
        cout << "* 4 - CALENDARIO             *" << endl;
        cout << "*                            *" << endl;
        cout << "* 5 - CALCULADORA DE TIEMPOS *" << endl;
        cout << "*                            *" << endl;
        cout << "******************************" << endl;
        cout << "*                            *" << endl;
        cout << "* 0 - SALIR                  *" << endl;
        cout << "*                            *" << endl;
        cout << "******************************" << endl;
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
            clienteMenu.iniciar();
            break;
        case 4:

            break;
        case 5:

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

void App::goodbye(){
    rlutil::setColor(rlutil::YELLOW);
    cout << "Gracias por usar JUST MAKE UP" << endl;
    cout << "Te esperamos pronto!" << endl;
    rlutil::setColor(rlutil::WHITE);
}
