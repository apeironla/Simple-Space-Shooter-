#include "Controller.h"
#include "Player.h"
#include "Includes.h"

Controller::Controller(int window_Identifier)
{
    originalwindow=window_Identifier;
    player = new Player();

}

void Controller::InitDisplay()
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0,640,0,480,-1,1);
    glMatrixMode(GL_MODELVIEW);
    currentwindow = glutGetWindow();

}

void Controller::Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    player->Draw();
    //    glBegin(GL_TRIANGLES);
//    glPointSize(5.0);
//    glVertex2d(0,0);
//    glVertex2d(320,240);
//    glVertex2d(640,0);
//    glEnd();


    glutSwapBuffers();
}

void Controller::KeyPressed(unsigned char key, int x, int y)
{
    int time = glutGet(GLUT_ELAPSED_TIME);
    switch(key)
    {
        case ' ':
            player->MakeShot(time);
            break;

    }
}
void Controller::SpecialKeyPressed(int key,int x, int y)
{
    int time = glutGet(GLUT_ELAPSED_TIME);
    player->SpecialKeyPressed(key,time);

}

void Controller:: SpecialKeyUpPressed(int key,int x, int y)
{
    //int time = glutGet(GLUT_ELAPSED_TIME);
    player->SpecialKeyUpPressed(key);

}

void Controller::Update()
{
    int time = glutGet((GLUT_ELAPSED_TIME));
    player->Update(time);

    glutPostWindowRedisplay(currentwindow);
}

void Controller::Initialize()
{
    InitDisplay();
    glutMainLoop();


}
Controller::~Controller()
{
    //dtor
}

