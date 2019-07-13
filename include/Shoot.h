#ifndef SHOOT_H
#define SHOOT_H

#include "Includes.h"
#include "GameLoop.h"
#include "Position.h"
#include "Bullet.h"
#include<cmath>

#include<vector>


class Shoot: public GameLoop
{
    public:
        Shoot();
        virtual ~Shoot();

        virtual void Draw();
        virtual void Update(int time, int delta);

        void MakeShot(int time, POSITION player_pos);
        void InitBullet(int i ,int time, POSITION player_pos);

        vector<Bullet> bullets;


    protected:

    private:
};

#endif // SHOOT_H
