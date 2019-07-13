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

    gun = new Shoot();



    //ctor
}

void Player:: Draw()
{
    glPushMatrix();

    glTranslatef(position.x,position.y,0);
    glColor3f(1.0,0.0,0.0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);

    glVertex2d(-15,0);
    glVertex2d(35,0);
    glVertex2d(20,20);
    glVertex2d(1,20);


    glEnd();
    glPopMatrix();

    if(gun != 0)gun->Draw();

}

void Player::MakeShot(int time)
{
    gun->MakeShot(time,position);
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
    cout<<time<<" "<<left_time<<" "<<right_time<<endl;
    if(left)
    {
        delta = time-left_time;
        position.x = position.x -delta*.08;
        left_time= time;
    }
    //cout<<position.x<< " "<<position.y<<endl;
    if(right)
    {
        delta = time-right_time;
        position.x = position.x +delta*.08;
        right_time= time;
    }


    position.y = position.y ;

    if(gun != 0)gun->Update(time,delta);


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
