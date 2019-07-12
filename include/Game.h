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





    protected:

    private:

        static int init(int argc, char ** argv);

        static Game* instance;
        Controller* controller;
};

#endif // GAME_H
