#ifndef GHOST2_H
#define GHOST2_H
#include "ghost.h"

class ghost2:public ghost
{
public:
    ghost2();
    virtual void move(int x,int y);
    int gd;
};

#endif // GHOST2_H
