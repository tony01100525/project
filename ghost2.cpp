#include "ghost2.h"
#include "mainwindow.h"
#include "game.h"

extern game *gw;

ghost2::ghost2()
{

}

void ghost2::move(int x, int y)
{

    if(gw->p->x()<gw->gh2->x()&&gw->walk(gw->gh2->x()-1,gw->gh2->y())){
        gw->gh2->setPos(gw->gh2->x()-1,gw->gh2->y());
        gd=0;
    }else if(gw->p->x()>gw->gh2->x()&&gw->walk(gw->gh2->x()+1,gw->gh2->y())){
        gw->gh2->setPos(gw->gh2->x()+1,gw->gh2->y());
        gd=1;
    }else if(gw->p->y()<gw->gh2->y()&&gw->walk(gw->gh2->x(),gw->gh2->y()-1)){
        gw->gh2->setPos(gw->gh2->x(),gw->gh2->y()-1);
        gd=2;
    }else if(gw->p->y()>gw->gh2->y()&&gw->walk(gw->gh2->x(),gw->gh2->y()+1)){
        gw->gh2->setPos(gw->gh2->x(),gw->gh2->y()+1);
        gd=3;
    }
    else{
        if(gw->gggg==0&&gw->walk(gw->gh2->x()-1,gw->gh2->y())){
            gd=0;

        }else if (gw->gggg == 1&&gw->walk(gw->gh2->x()+1,gw->gh2->y())) {
             gd=2;

        }else if (gw->gggg == 2&&gw->walk(gw->gh2->x(),gw->gh2->y()-1)) {
             gd=1;

        }else if (gw->gggg == 3&&gw->walk(gw->gh2->x(),gw->gh2->y()+1)) {
             gd=3;

        }
    }
}
