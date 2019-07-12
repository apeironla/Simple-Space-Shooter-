#ifndef GAMELOOP_H
#define GAMELOOP_H
#include "Includes.h"


class GameLoop
{
    public:
        GameLoop();
        virtual ~GameLoop();
        virtual void Update(int time, int delta=0)=0;
        virtual void Draw()=0;

    protected:

    private:
};

#endif // GAMELOOP_H
