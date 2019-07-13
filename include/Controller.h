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
    void KeyPressed(unsigned char key, int x, int y);
    void SpecialKeyPressed(int key,int x, int y);
    void SpecialKeyUpPressed(int key, int x, int y);
    void Update();

protected:

private:

    void InitDisplay();


    int originalwindow;
    int currentwindow;
    Player* player;
};

#endif // CONTROLLER_H
