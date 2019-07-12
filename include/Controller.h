#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Includes.h"
#include "Player.h"


class Controller
{
public:
    Controller(int window_Identifier);
    virtual ~Controller();
    void Initialize();
    void Display();

protected:

private:

    void InitDisplay();


    int originalwindow;
    Player* player;
};

#endif // CONTROLLER_H
