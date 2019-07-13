#ifndef GAME_H
#define GAME_H

#include "Includes.h"
#include "Controller.h"



class Game
{
    public:
        Game( int window_Identifier);
        virtual ~Game();
        static bool NewGame(int argc , char** argv);
        static void Display();
        static void InitHandlers();
        static void KeyPressed(unsigned char key, int x, int y);
        static void SpecialKeyPressed(int key , int x, int y);
        static void SpecialKeyUpPressed(int key, int x, int y);
        static void Update();
        static void Visible(int vis);





    protected:

    private:

        static int init(int argc, char ** argv);

        static Game* instance;
        Controller* controller;
};

#endif // GAME_H
