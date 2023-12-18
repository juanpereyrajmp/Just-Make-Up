#ifndef CLIENTEMENU_H
#define CLIENTEMENU_H

#include "ClienteManager.h"
#include "ClienteListarMenu.h"

class ClienteMenu{
private:
    ClienteManager clienteManager;
    ClienteListarMenu clienteListarMenu;

public:
    void iniciar();
};

#endif // CLIENTEMENU_H
