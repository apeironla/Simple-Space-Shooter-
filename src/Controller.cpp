#include "Controller.h"

Controller::Controller(int window_Identifier)
{
    originalwindow=window_Identifier;

}

void Controller::InitDisplay()
{
    glClearColor(0,0,0,0);
    glShadeModel(GL_FLAT);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    glOrtho(0,640,0,480,-1,1);
    glMatrixMode(GL_MODELVIEW);

}

void Controller::Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glPointSize(5.0);
    glVertex2d(0,0);
    glVertex2d(320,240);
    glVertex2d(640,0);
    glEnd();


    glutSwapBuffers();
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

