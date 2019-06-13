#include "ghost3.h"
#include "mainwindow.h"
#include "game.h"

extern game *gw;

ghost3::ghost3()
{

}

void ghost3::move(int x, int y)
{
    a=abs(gw->p->x()-gw->gh3->x());
    b=abs(gw->p->y()-gw->gh3->y());
    //qDebug()<<gw->c;
    if((a*a+b*b)>12800&&gw->c==0){
        if(gw->p->x()<gw->gh3->x()&&gw->walk(gw->gh3->x()-1,gw->gh3->y())){
            gw->gh3->setPos(gw->gh3->x()-1,gw->gh3->y());
        }else if(gw->p->x()>gw->gh3->x()&&gw->walk(gw->gh3->x()+1,gw->gh3->y())){
            gw->gh3->setPos(gw->gh3->x()+1,gw->gh3->y());
        }else if(gw->p->y()<gw->gh3->y()&&gw->walk(gw->gh3->x(),gw->gh3->y()-1)){
            gw->gh3->setPos(gw->gh3->x(),gw->gh3->y()-1);
        }else if(gw->p->y()>gw->gh3->y()&&gw->walk(gw->gh3->x(),gw->gh3->y()+1)){
            gw->gh3->setPos(gw->gh3->x(),gw->gh3->y()+1);
        }
        if((a*a+b*b)<13000){
            gw->c=1;
        }
    }else if(gw->c==1){
        if(gw->gg3==0){
            if(600>gw->gh3->y()&&gw->walk(gw->gh3->x(),gw->gh3->y()+1)&&gd==2){
                gw->gh3->setPos(gw->gh3->x(),gw->gh3->y()+1);
                gd=2;


            }else if(20<gw->gh3->x()&&gw->walk(gw->gh3->x()-1,gw->gh3->y())){
                gw->gh3->setPos(gw->gh3->x()-1,gw->gh3->y());
            }else if(gw->cantwalk(gw->gh3->x(),gw->gh3->y()+1)||gw->cantwalk(gw->gh3->x()-1,gw->gh3->y())){
                gw->gh3->setPos(gw->gh1->x()+1,gw->gh3->y());
                gd=0;
                if(gw->walk(gw->gh3->x(),gw->gh3->y()+1)){
                    gd=2;
                }
            }
            if(gw->gh3->x()==20||gw->gh3->y()==600){
                gw->c=0;
            }
        }/*else{
            if(600<gw->gh3->y()&&gw->walk(gw->gh3->x(),gw->gh3->y()+1)){
                gw->gh3->setPos(gw->gh3->x(),gw->gh3->y()+1);
            }else if(540>gw->gh3->x()&&gw->walk(gw->gh3->x()+1,gw->gh3->y())){
                gw->gh3->setPos(gw->gh3->x()+1,gw->gh3->y());
            }
            if(gw->gh3->x()==540||gw->gh3->y()==600){
                c=0;
            }
        }*/

    }

}
