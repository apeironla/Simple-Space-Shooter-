#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Includes.h"
#include "GameLoop.h"


class Player:public GameLoop
{
    public:
        Player();
        virtual ~Player();
        virtual void Update(int time,int delta=0);
        virtual void Draw();

        void SpecialKeyPressed(int key,int time);
        void SpecialKeyUpPressed(int key);

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


};

#endif // PLAYER_H
