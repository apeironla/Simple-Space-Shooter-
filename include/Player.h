#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Includes.h"
#include "GameLoop.h"
#include "Shoot.h"


class Player:public GameLoop
{
    public:
        Player();
        virtual ~Player();
        virtual void Update(int time,int delta=0);
        virtual void Draw();

        void SpecialKeyPressed(int key,int time);
        void SpecialKeyUpPressed(int key);
        void MakeShot(int time);

    protected:

    private:
        int time;
        int left_time;
        int right_time;
        bool left;
        bool right;


        int last_time;

        int _v;
        POSITION position;
        Shoot* gun;


};

#endif // PLAYER_H
