#ifndef GHOST4_H
#define GHOST4_H
#include "ghost.h"

class ghost4:public ghost
{
public:
    ghost4();
    virtual void move(int x,int y);
    int gd=0,nd=1;
};
#endif // GHOST4_H
