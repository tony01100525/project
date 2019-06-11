#include "ghost1.h"
#include "mainwindow.h"
#include "game.h"

extern game *gw;
ghost1::ghost1()
{

}

void ghost1::move(int x, int y)
{

        if(gw->gg1==0&&gw->walk(gw->gh1->x()-1,gw->gh1->y())){
            gw->gh1->setPos(gw->gh1->x()-1,gw->gh1->y());
            if(gw->ggg==0&&gw->cantwalk(gw->gh1->x()-1,gw->gh1->y())&&gw->walk(gw->gh1->x()+1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()+1,gw->gh1->y());
                gw->gg1=gw->ggg+1;
            }else if(gw->ggg==1&&gw->cantwalk(gw->gh1->x()-1,gw->gh1->y())&&gw->walk(gw->gh1->x(),gw->gh1->y()-1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()-1);
                gw->gg1=gw->ggg+1;
            }else if(gw->ggg==2&&gw->cantwalk(gw->gh1->x()-1,gw->gh1->y())&&gw->walk(gw->gh1->x(),gw->gh1->y()+1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()+1);
                gw->gg1=gw->ggg+1;
            }
        }else if (gw->gg1 == 1&&gw->walk(gw->gh1->x()+1,gw->gh1->y())) {
            gw->gh1->setPos(gw->gh1->x()+1,gw->gh1->y());
            if(gw->ggg==2&&gw->cantwalk(gw->gh1->x()+1,gw->gh1->y())&&gw->walk(gw->gh1->x(),gw->gh1->y()-1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()-1);
                gw->gg1=gw->ggg;
            }else if(gw->ggg==1&&gw->cantwalk(gw->gh1->x()+1,gw->gh1->y())&&gw->walk(gw->gh1->x(),gw->gh1->y()+1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()+1);
                gw->gg1=gw->ggg+2;
            }else if(gw->ggg==0&&gw->cantwalk(gw->gh1->x()+1,gw->gh1->y())&&gw->walk(gw->gh1->x()-1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()-1,gw->gh1->y());
                gw->gg1=gw->ggg;
            }
        }else if (gw->gg1 == 2&&gw->walk(gw->gh1->x(),gw->gh1->y()-1)) {
            gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()-1);
            if(gw->ggg==2&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()-1)&&gw->walk(gw->gh1->x(),gw->gh1->y()+1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()+1);
                gw->gg1=gw->ggg+1;
            }else if(gw->ggg==0&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()-1)&&gw->walk(gw->gh1->x()-1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()-1,gw->gh1->y());
                gw->gg1=gw->ggg;
            }else if(gw->ggg==1&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()-1)&&gw->walk(gw->gh1->x()+1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()+1,gw->gh1->y());
                gw->gg1=gw->ggg;
            }
        }else if (gw->gg1 == 3&&gw->walk(gw->gh1->x(),gw->gh1->y()+1)) {
            gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()+1);
            if(gw->ggg==0&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()+1)&&gw->walk(gw->gh1->x()-1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()-1,gw->gh1->y());
                gw->gg1=gw->ggg;
            }else if(gw->ggg==1&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()+1)&&gw->walk(gw->gh1->x()+1,gw->gh1->y())){
                gw->gh1->setPos(gw->gh1->x()+1,gw->gh1->y());
                gw->gg1=gw->ggg;
            }else if(gw->ggg==2&&gw->cantwalk(gw->gh1->x(),gw->gh1->y()+1)&&gw->walk(gw->gh1->x(),gw->gh1->y()-1)){
                gw->gh1->setPos(gw->gh1->x(),gw->gh1->y()-1);
                gw->gg1=gw->ggg;
            }
        }else{
            gw->gg1=qrand()%4;
        }

}


