#ifndef GHOST3_H
#define GHOST3_H
#include "ghost.h"
#include <QDebug>
#include <math.h>

class ghost3:public ghost
{
public:
    ghost3();
    virtual void move(int x,int y);
    int a,b,c,gd=2;
};

#endif // GHOST3_H
