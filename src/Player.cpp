#include "Player.h"

Player::Player()
{
    time =0;
    left_time =0;
    right_time=0;
    left =0;
    right =0;
    last_time=0;


    position.x = 640/2;
    position.y =0;



    //ctor
}

void Player:: Draw()
{

    glTranslatef(position.x,position.y,0);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);

    glVertex2d(-15,0);
    glVertex2d(35,0);
    glVertex2d(20,20);
    glVertex2d(1,20);


    glEnd();

}
void Player::SpecialKeyPressed(int key, int time)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        left=1;
        left_time=time;
        break;
    case GLUT_KEY_RIGHT:
        right=1;
        right_time=time;
        break;
    }
}

void Player::Update(int time, int delta)
{
//    cout<<time<<endl;
    if(left)
    {
        delta = time-left_time;
        left_time= time;
    }

    _v = delta*.00004;
    position.x = position.x + _v*delta;
    position.y = position.y + _v*delta;


}


void Player::SpecialKeyUpPressed(int key)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        left=0;
        break;
    case GLUT_KEY_RIGHT:
        right=0;
        break;
    }
}
Player::~Player()
{
    //dtor
}
