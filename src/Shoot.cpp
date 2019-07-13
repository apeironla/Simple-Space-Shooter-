#include "Shoot.h"

Shoot::Shoot()
{
    //ctor
    for(int i =0; i<15; i++)
    {
        Bullet b;
        bullets.push_back(b);
    }
}

void Shoot::MakeShot(int time, POSITION player_pos)
{
    size_t count = bullets.size();
    for(size_t i=0; i<count; i++)
    {
        if(!bullets[i].inuse)
            InitBullet(i,time,player_pos);
    }
}
void Shoot:: InitBullet(int i,int time, POSITION player_pos)
{
    float angle = 90;
    double c = cos((angle*M_PI));
    double s = sin((angle*M_PI));
    bullets[i].inuse =1;
    float vel= .06;
    bullets[i].x = player_pos.x * c / 180 ;
    bullets[i].y = (player_pos.y+10)*s/180;
//    bullets[i].xv = c * vel;
//    bullets[i].yv = s * vel;
    bullets[i].expire = time + 2000;
}


void Shoot:: Draw()
{
    glBegin(GL_POINTS);
    glPointSize(10);
    glColor3f(1.0, 0.0, 0.0);

    size_t count = bullets.size();
    for (size_t i=0; i<count; i++)
    {
        if (bullets[i].inuse)
        {
            glVertex2f(bullets[i].x, bullets[i].y);
        }
    }

    glEnd();
}

void Shoot:: Update(int time, int delta)
{
    size_t counts = bullets.size();
    for (size_t i=0; i<counts; i++)
    {
        if (bullets[i].inuse)
        {
            if(time>bullets[i].expire)
            {
                bullets[i].inuse=0;
                continue;
            }
            float x = bullets[i].x + bullets[i].xv * delta;
            float y = bullets[i].y + bullets[i].yv * delta;
            x = x / 100;
            bullets[i].x = (x - floor(x))*100;
            y = y /100;
            bullets[i].y = (y - floor(y))*100;

        }
    }

}

Shoot::~Shoot()
{
    //dtor
}
