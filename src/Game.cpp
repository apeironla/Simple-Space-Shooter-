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
    glutKeyboardFunc(&Game::KeyPressed);
    glutSpecialFunc(&Game::SpecialKeyPressed);
    glutSpecialUpFunc(&Game::SpecialKeyUpPressed);
    glutDisplayFunc(&Game::Display);
    glutVisibilityFunc(&Game::Visible);

}
void Game::Display()
{
    instance->controller->Display();
}

void Game::KeyPressed(unsigned char key , int x, int y)
{
    instance->controller->KeyPressed(key,x,y);

}

int Game::init(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    return glutCreateWindow("SHOOTING GAME");
}

void Game:: SpecialKeyPressed(int key, int x, int y)
{
    instance->controller->SpecialKeyPressed(key, x,y);
}

void Game:: SpecialKeyUpPressed(int key, int x, int y)
{
    instance->controller->SpecialKeyUpPressed(key, x,y);
}

void Game:: Update()
{
    instance->controller->Update();
}

void Game:: Visible(int vis)
{
    if(vis == GLUT_VISIBLE)
    {
        glutIdleFunc(&Game::Update);
    }
    else glutIdleFunc(NULL);
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
