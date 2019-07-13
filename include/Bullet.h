#ifndef BULLET_H
#define BULLET_H


struct Bullet
{

    bool inuse;
    float x;
    float y;
    float xv;
    float yv;
    int expire;
};

#endif // BULLET_H
