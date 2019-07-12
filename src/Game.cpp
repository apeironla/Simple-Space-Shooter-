#include "Game.h"



Game* Game::instance =0;

Game::Game(int window_Identifier)
{
    controller = new Controller(window_Identifier);
    //ctor
}

bool Game::NewGame(int argc, char** argv)
{
    if(instance==0)
    {
        instance = new Game(init(argc,argv));
        //instance->controller->Display();
        Game::InitHandlers();
        instance->controller->Initialize();

        return true;
    }
    else
        return false;



    //return
}
void Game::InitHandlers()
{
    glutDisplayFunc(&Game::Display);
}
void Game::Display()
{
    instance->controller->Display();
}

int Game::init(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    return glutCreateWindow("SHOOTING GAME");
}

Game::~Game()
{
    if (controller != 0)
    {
        delete controller;
        controller = 0;
    }
    //dtor
}
