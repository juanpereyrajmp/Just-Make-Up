#ifndef APP_H
#define APP_H

#include "rlutil.h"
#include "ClienteMenu.h"

class App{
private:
    ClienteMenu clienteMenu;

public:
    void run();
    void goodbye();
};

#endif // APP_H
