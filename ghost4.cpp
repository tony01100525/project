#include "ghost4.h"
#include "mainwindow.h"
#include "game.h"

extern game *gw;

ghost4::ghost4()
{

}

void ghost4::move(int x, int y)
{

    if(nd==0&&gw->walk(gw->gh4->x()+1,gw->gh4->y())){
        gw->gh4->setPos(gw->gh4->x()+1,gw->gh4->y());
        nd=0;
        if(gw->walk(gw->gh4->x()+1,gw->gh4->y())&&gw->gg4==0){
            nd=0;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()+1)&&gw->gg4==1){
            nd=2;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()-1)&&gw->gg4==2){
            nd=3;
        }
    }else if(nd==1&&gw->walk(gw->gh4->x()-1,gw->gh4->y())){
        gw->gh4->setPos(gw->gh4->x()-1,gw->gh4->y());
        nd=1;
        if(gw->walk(gw->gh4->x()-1,gw->gh4->y())&&gw->gg4==0){
            nd=1;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()+1)&&gw->gg4==1){
            nd=2;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()-1)&&gw->gg4==2){
            nd=3;
        }
    }else if(nd==2&&gw->walk(gw->gh4->x(),gw->gh4->y()+1)){
        gw->gh4->setPos(gw->gh4->x(),gw->gh4->y()+1);
        nd=2;
        if(gw->walk(gw->gh4->x()+1,gw->gh4->y())&&gw->gg4==0){
            nd=0;
        }else if(gw->walk(gw->gh4->x()-1,gw->gh4->y())&&gw->gg4==1){
            nd=1;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()+1)&&gw->gg4==2){
            nd=2;
        }
    }else if(nd==3&&gw->walk(gw->gh4->x(),gw->gh4->y()-1)){
        gw->gh4->setPos(gw->gh4->x(),gw->gh4->y()-1);
        nd=3;
        if(gw->walk(gw->gh4->x()+1,gw->gh4->y())&&gw->gg4==0){
            nd=0;
        }else if(gw->walk(gw->gh4->x()-1,gw->gh4->y())&&gw->gg4==1){
            nd=1;
        }else if(gw->walk(gw->gh4->x(),gw->gh4->y()-1)&&gw->gg4==2){
            nd=3;
        }
    }else{
        nd=gw->gg4;
    }

    if(gw->gh4->x()==-20&&gw->gh4->y()==280){
        gw->gh4->setPos(28*20,280);
    }else if(gw->gh4->x()==28*20&&gw->gh4->y()==280){
        gw->gh4->setPos(-20,280);
    }
    //qDebug()<<gd<<" "<<gw->gg4;
}
