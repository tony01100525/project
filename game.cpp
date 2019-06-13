#include "game.h"
#include "ui_game.h"
#include <QKeyEvent>
#include <QDebug>


game::game(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(
                0, 0,
                ui->graphicsView->width() - 2,
                ui->graphicsView->height() - 2
                );


    board.load(":/new/prefix1/board");
    pac.load(":/new/prefix2/pacman");
    for (i=0;i<244;++i) {
        dot[i].load(":/new/prefix3/dot");
    }
    g1.load(":/new/prefix4/g1");
    g2.load(":/new/prefix4/g2");
    g3.load(":/new/prefix4/g3");
    g4.load(":/new/prefix4/g4");
    for (i=0;i<4;++i) {
        power[i].load(":/new/prefix3/power");
    }



    board = board.scaled(560,620);
    pac = pac.scaled(20,20);
    for (i=0;i<244;++i) {
        dot[i] = dot[i].scaled(20,20);
    }
    g1 = g1.scaled(20,20);
    g2 = g2.scaled(20,20);
    g3 = g3.scaled(20,20);
    g4 = g4.scaled(20,20);
    for (i=0;i<4;++i) {
        power[i] = power[i].scaled(20,20);
    }


    scene->addPixmap(board);
    p = scene->addPixmap(pac);
    for (i=0;i<244;++i) {
        d[i] = scene->addPixmap(dot[i]);
    }
    gh1 = scene->addPixmap(g1);
    gh2 = scene->addPixmap(g2);
    gh3 = scene->addPixmap(g3);
    gh4 = scene->addPixmap(g4);
    for (i=0;i<4;++i) {
        pow[i] = scene->addPixmap(power[i]);
    }


    gh1->setPos(20,80);
    gh2->setPos(520,80);
    gh3->setPos(20,580);
    gh4->setPos(520,580);
    p->setPos(20,50);
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    pow[0]->setPos(20,60);
    pow[1]->setPos(20,440);
    pow[2]->setPos(520,60);
    pow[3]->setPos(520,440);
    i=0;
    for (r=1;r<29;++r) {
        if(r==2||r==27){
            for (k=1;k<9;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            for (k=20;k<24;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            for (k=26;k<30;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
        }
        if(r==3||r==11||r==12||r==26||r==18||r==17){
            d[i]->setPos(20*(r-1),20*1);
            i+=1;
            d[i]->setPos(20*(r-1),20*5);
            i+=1;
            d[i]->setPos(20*(r-1),20*8);
            i+=1;
            d[i]->setPos(20*(r-1),20*20);
            i+=1;
            d[i]->setPos(20*(r-1),20*23);
            i+=1;
            d[i]->setPos(20*(r-1),20*26);
            i+=1;
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==4||r==25){
            d[i]->setPos(20*(r-1),20*1);
            i+=1;
            d[i]->setPos(20*(r-1),20*5);
            i+=1;
            d[i]->setPos(20*(r-1),20*8);
            i+=1;
            d[i]->setPos(20*(r-1),20*20);
            i+=1;
            for (k=23;k<27;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==5||r==6||r==23||r==24){
            d[i]->setPos(20*(r-1),20*1);
            i+=1;
            d[i]->setPos(20*(r-1),20*5);
            i+=1;
            d[i]->setPos(20*(r-1),20*8);
            i+=1;
            d[i]->setPos(20*(r-1),20*20);
            i+=1;
            d[i]->setPos(20*(r-1),20*26);
            i+=1;
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==7||r==22){
            for (k=1;k<27;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==8||r==9||r==20||r==21){
            d[i]->setPos(20*(r-1),20*1);
            i+=1;
            d[i]->setPos(20*(r-1),20*5);
            i+=1;
            d[i]->setPos(20*(r-1),20*20);
            i+=1;
            d[i]->setPos(20*(r-1),20*23);
            i+=1;
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==10||r==19){
            d[i]->setPos(20*(r-1),20*1);
            i+=1;
            for (k=5;k<9;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            d[i]->setPos(20*(r-1),20*20);
            i+=1;
            for (k=23;k<27;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
        if(r==13||r==16){
            for (k=1;k<6;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            d[i]->setPos(20*(r-1),20*8);
            i+=1;
            for (k=20;k<24;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
            for (k=26;k<30;++k) {
                d[i]->setPos(20*(r-1),20*k);
                i+=1;
            }
        }
        if(r==14||r==15){
            d[i]->setPos(20*(r-1),20*5);
            i+=1;
            d[i]->setPos(20*(r-1),20*29);
            i+=1;
        }
    }
    now = new QTimer;
    now->start(10);
    connect(now,SIGNAL(timeout()),this,SLOT(move()));
    gt1 = new QTimer;
    gt1->start(300);
    connect(gt1,SIGNAL(timeout()),this,SLOT(g1move()));
    gt2 = new QTimer;
    gt2->start(500);
    connect(gt2,SIGNAL(timeout()),this,SLOT(gggmove()));

    ui->graphicsView->setScene(scene);
    ui->line->hide();
    ui->line2->hide();

}

void game::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_A){
        //p->setPos(p->x()-(now->elapsed()/1000),p->y());
        m=0;
    }
    if(event->key() == Qt::Key_D){
        m=1;
    }
    if(event->key() == Qt::Key_W){
        m=2;
    }
    if(event->key() == Qt::Key_S){
        m=3;
    }
    if(event->key() == Qt::Key_P&&P==0){
        now->stop();
        P=1;
    }
    else if(event->key() == Qt::Key_P&&P==1){
        now->start();
        P=0;
    }
}

bool game::walk(int x, int y)
{
            if (x<=20*12&&x>=20*1&&y==20) {
                return true;
            }
            if (x==20*1&&y>=20&&y<=160) {
                return true;
            }
            if (x<=20*26&&x>=20*1&&y==100) {
                return true;
            }
            if (x<=20*6&&x>=20*1&&y==160) {
                return true;
            }
            if (x<=20*9&&x>=-20&&y==280) {
                return true;
            }
            if (x<=20*12&&x>=20*1&&y==400) {
                return true;
            }
            if (x==20*1&&y>=400&&y<=460) {
                return true;
            }
            if (x<=20*3&&x>=20*1&&y==460) {
                return true;
            }
            if (x<=20*6&&x>=20*1&&y==520) {
                return true;
            }
            if (x==20*1&&y>=520&&y<=580) {
                return true;
            }
            if (x<=20*26&&x>=20*1&&y==580) {
                return true;
            }
        //if(r==4){
            if (x==20*3&&y>=460&&y<=520) {
                return true;
            }
        //if(r==7){
            if (x==20*6&&y>=20&&y<=520) {
                return true;
            }
            if (x<=20*21&&x>=20*6&&y==460) {
                return true;
            }
        //if(r==10){
            if (x==20*9&&y>=100&&y<=160) {
                return true;
            }
            if (x<=20*12&&x>=20*9&&y==160) {
                return true;
            }
            if (x<=20*18&&x>=20*9&&y==220) {
                return true;
            }
            if (x==20*9&&y>=220&&y<=400) {
                return true;
            }
            if (x<=20*18&&x>=20*9&&y==340) {
                return true;
            }
            if (x==20*9&&y>=460&&y<=520) {
                return true;
            }
            if (x<=20*12&&x>=20*9&&y==520) {
                return true;
            }

        //if(r==13){
            if (x==20*12&&y>=20&&y<=100) {
                return true;
            }
            if (x==20*12&&y>=160&&y<=220) {
                return true;
            }
            if (x==20*12&&y>=400&&y<=460) {
                return true;
            }
            if (x==20*12&&y>=520&&y<=580) {
                return true;
            }
        //if(r==16){
            if (x<=20*26&&x>=20*15&&y==20) {
                return true;
            }
            if (x==20*15&&y>=20&&y<=100) {
                return true;
            }
            if (x<=20*18&&x>=20*15&&y==160) {
                return true;
            }
            if (x==20*15&&y>=160&&y<=220) {
                return true;
            }
            if (x<=20*26&&x>=20*15&&y==400) {
                return true;
            }
            if (x==20*15&&y>=400&&y<=460) {
                return true;
            }
            if (x<=20*18&&x>=20*15&&y==520) {
                return true;
            }
            if (x==20*15&&y>=520&&y<=580) {
                return true;
            }
        //if(r==19){
            if (x==20*18&&y>=100&&y<=160) {
                return true;
            }
            if (x==20*18&&y>=220&&y<=400) {
                return true;
            }
            if (x<=20*28&&x>=20*18&&y==280) {
                return true;
            }
            if (x==20*18&&y>=460&&y<=520) {
                return true;
            }
        //if(r==22){
            if (x==20*21&&y>=20&&y<=520) {
                return true;
            }
            if (x<=20*26&&x>=20*21&&y==160) {
                return true;
            }
            if (x<=20*26&&x>=20*21&&y==520) {
                return true;
            }
        //if(r==25){
            if (x<=20*26&&x>=20*24&&y==460) {
                return true;
            }
            if (x==20*24&&y>=460&&y<=520) {
                return true;
            }
        //if(r==27){
            if (x==20*26&&y>=20&&y<=160) {
                return true;
            }
            if (x==20*26&&y>=400&&y<=460) {
                return true;
            }
            if (x==20*26&&y>=520&&y<=580) {
                return true;
            }

    /*if(x==20&&y>=460){
        //qDebug()<<p->x();
        return true;
    }*/
            return false;
}

bool game::cantwalk(int x, int y)
{
    if (x<=20*12&&x>=20*1&&y==20) {
        return false;
    }
    if (x==20*1&&y>=20&&y<=160) {
        return false;
    }
    if (x<=20*26&&x>=20*1&&y==100) {
        return false;
    }
    if (x<=20*6&&x>=20*1&&y==160) {
        return false;
    }
    if (x<=20*9&&x>=-20&&y==280) {
        return false;
    }
    if (x<=20*12&&x>=20*1&&y==400) {
        return false;
    }
    if (x==20*1&&y>=400&&y<=460) {
        return false;
    }
    if (x<=20*3&&x>=20*1&&y==460) {
        return false;
    }
    if (x<=20*6&&x>=20*1&&y==520) {
        return false;
    }
    if (x==20*1&&y>=520&&y<=580) {
        return false;
    }
    if (x<=20*26&&x>=20*1&&y==580) {
        return false;
    }
//if(r==4){
    if (x==20*3&&y>=460&&y<=520) {
        return false;
    }
//if(r==7){
    if (x==20*6&&y>=20&&y<=520) {
        return false;
    }
    if (x<=20*21&&x>=20*6&&y==460) {
        return false;
    }
//if(r==10){
    if (x==20*9&&y>=100&&y<=160) {
        return false;
    }
    if (x<=20*12&&x>=20*9&&y==160) {
        return false;
    }
    if (x<=20*18&&x>=20*9&&y==220) {
        return false;
    }
    if (x==20*9&&y>=220&&y<=400) {
        return false;
    }
    if (x<=20*18&&x>=20*9&&y==340) {
        return false;
    }
    if (x==20*9&&y>=460&&y<=520) {
        return false;
    }
    if (x<=20*12&&x>=20*9&&y==520) {
        return false;
    }

//if(r==13){
    if (x==20*12&&y>=20&&y<=100) {
        return false;
    }
    if (x==20*12&&y>=160&&y<=220) {
        return false;
    }
    if (x==20*12&&y>=400&&y<=460) {
        return false;
    }
    if (x==20*12&&y>=520&&y<=580) {
        return false;
    }
//if(r==16){
    if (x<=20*26&&x>=20*15&&y==20) {
        return false;
    }
    if (x==20*15&&y>=20&&y<=100) {
        return false;
    }
    if (x<=20*18&&x>=20*15&&y==160) {
        return false;
    }
    if (x==20*15&&y>=160&&y<=220) {
        return false;
    }
    if (x<=20*26&&x>=20*15&&y==400) {
        return false;
    }
    if (x==20*15&&y>=400&&y<=460) {
        return false;
    }
    if (x<=20*18&&x>=20*15&&y==520) {
        return false;
    }
    if (x==20*15&&y>=520&&y<=580) {
        return false;
    }
//if(r==19){
    if (x==20*18&&y>=100&&y<=160) {
        return false;
    }
    if (x==20*18&&y>=220&&y<=400) {
        return false;
    }
    if (x<=20*28&&x>=20*18&&y==280) {
        return false;
    }
    if (x==20*18&&y>=460&&y<=520) {
        return false;
    }
//if(r==22){
    if (x==20*21&&y>=20&&y<=520) {
        return false;
    }
    if (x<=20*26&&x>=20*21&&y==160) {
        return false;
    }
    if (x<=20*26&&x>=20*21&&y==520) {
        return false;
    }
//if(r==25){
    if (x<=20*26&&x>=20*24&&y==460) {
        return false;
    }
    if (x==20*24&&y>=460&&y<=520) {
        return false;
    }
//if(r==27){
    if (x==20*26&&y>=20&&y<=160) {
        return false;
    }
    if (x==20*26&&y>=400&&y<=460) {
        return false;
    }
    if (x==20*26&&y>=520&&y<=580) {
        return false;
    }

    return true;
}



void game::move()
{

    if(p->x()==-20&&p->y()==280){
        p->setPos(28*20,280);
    }else if(p->x()==28*20&&p->y()==280){
        p->setPos(-20,280);
    }
        if(m==0&&walk(p->x()-1,p->y())){
            f=0;
            p->setPos(p->x()-1,p->y());
        }else if (m == 1&&walk(p->x()+1,p->y())) {
            f=1;
            p->setPos(p->x()+1,p->y());
        }else if (m == 2&&walk(p->x(),p->y()-1)) {
            f=2;
            p->setPos(p->x(),p->y()-1);
        }else if (m == 3&&walk(p->x(),p->y()+1)) {
            f=3;
            p->setPos(p->x(),p->y()+1);
        }else if(f==0&&walk(p->x()-1,p->y())){
            p->setPos(p->x()-1,p->y());
        }else if (f==1&&walk(p->x()+1,p->y())) {
            p->setPos(p->x()+1,p->y());
        }else if (f==2&&walk(p->x(),p->y()-1)) {
            p->setPos(p->x(),p->y()-1);
        }else if (f==3&&walk(p->x(),p->y()+1)) {
            p->setPos(p->x(),p->y()+1);
        }




        /*else{

            if(f==0&&walk(p->x()-1,p->y())){
                p->setPos(p->x()-1,p->y());
            }else if (f == 1&&walk(p->x()+1,p->y())) {
                p->setPos(p->x()+1,p->y());
            }else if (f == 2&&walk(p->x(),p->y()-1)) {
                p->setPos(p->x(),p->y()-1);
            }else if (f == 3&&walk(p->x(),p->y()+1)) {
                p->setPos(p->x(),p->y()+1);
            }
        }*/
    for (i=0;i<244;++i) {
        if(p->x()==d[i]->x()&&p->y()==d[i]->y()&&dd[i]==0){
            d[i]->hide();
            dd[i]+=1;
            score+=10;
            over+=1;
            //qDebug()<<score;
            ui->lcd->display(score);
        }
    }
    for (i=0;i<4;++i) {
        if(p->x()==pow[i]->x()&&p->y()==pow[i]->y()&&pp[i]==0){
            pow[i]->hide();
            pp[i]+=1;
            score+=40;
            //qDebug()<<score;
            ui->lcd->display(score);
            ppt=1;
            pt = new QTimer;
            pt->start(8000);
            connect(pt,SIGNAL(timeout()),this,SLOT(ptime()));
        }
    }
    if(over==244){
        ui->line->show();
    }
    if(ppt==1||ppt==2){
        g5.load(":/new/prefix4/g5");

        g5 = g5.scaled(20,20);

        gh1->setPixmap(g5);
        gh2->setPixmap(g5);
        gh3->setPixmap(g5);
        gh4->setPixmap(g5);


        ppt=2;
    }else   if(ppt==0){
        if(gh1->x()==-20&&gh1->y()==0){
            gh1->setPos(20,80);
        }
        if(gh2->x()==-20&&gh2->y()==0){
            gh2->setPos(520,80);
        }
        if(gh3->x()==-20&&gh3->y()==0){
            gh3->setPos(20,580);
        }
        if(gh4->x()==-20&&gh4->y()==0){
            gh4->setPos(520,580);
        }
        gh1->setPixmap(g1);
        gh2->setPixmap(g2);
        gh3->setPixmap(g3);
        gh4->setPixmap(g4);
    }


    ghost11.move(gh1->x(),gh1->y());

    ghost22.move(gh2->x(),gh2->y());


    ghost33.move(gh3->x(),gh3->y());

    ghost44.move(gh4->x(),gh4->y());

    /*if(gg1==0&&walk(gh1->x()-1,gh1->y())){
        gh1->setPos(gh1->x()-1,gh1->y());
    }else if (gg1 == 1&&walk(gh1->x()+1,gh1->y())) {
        gh1->setPos(gh1->x()+1,gh1->y());
    }else if (gg1 == 2&&walk(gh1->x(),gh1->y()-1)) {
        gh1->setPos(gh1->x(),gh1->y()-1);
    }else if (gg1 == 3&&walk(gh1->x(),gh1->y()+1)) {
        gh1->setPos(gh1->x(),gh1->y()+1);
    }*/

    /*if(gg2==0&&walk(gh2->x()-1,gh2->y())){
        gh2->setPos(gh2->x()-1,gh2->y());
    }else if (gg2 == 1&&walk(gh2->x()+1,gh2->y())) {
        gh2->setPos(gh2->x()+1,gh2->y());
    }else if (gg2 == 2&&walk(gh2->x(),gh2->y()-1)) {
        gh2->setPos(gh2->x(),gh2->y()-1);
    }else if (gg2 == 3&&walk(gh2->x(),gh2->y()+1)) {
        gh2->setPos(gh2->x(),gh2->y()+1);
    }

    if(gg3==0&&walk(gh3->x()-1,gh3->y())){
        gh3->setPos(gh3->x()-1,gh3->y());
    }else if (gg3 == 1&&walk(gh3->x()+1,gh3->y())) {
        gh3->setPos(gh3->x()+1,gh3->y());
    }else if (gg3 == 2&&walk(gh3->x(),gh3->y()-1)) {
        gh3->setPos(gh3->x(),gh3->y()-1);
    }else if (gg3 == 3&&walk(gh3->x(),gh3->y()+1)) {
        gh3->setPos(gh3->x(),gh3->y()+1);
    }

    if(gg4==0&&walk(gh4->x()-1,gh4->y())){
        gh4->setPos(gh4->x()-1,gh4->y());
    }else if (gg4 == 1&&walk(gh4->x()+1,gh4->y())) {
        gh4->setPos(gh4->x()+1,gh4->y());
    }else if (gg4 == 2&&walk(gh4->x(),gh4->y()-1)) {
        gh4->setPos(gh4->x(),gh4->y()-1);
    }else if (gg4 == 3&&walk(gh4->x(),gh4->y()+1)) {
        gh4->setPos(gh4->x(),gh4->y()+1);
    }*/

    /*if(p->x()==gh1->x()&&p->y()==gh1->y()||p->x()==gh2->x()&&p->y()==gh2->y()
            ||p->x()==gh3->x()&&p->y()==gh3->y()||p->x()==gh4->x()&&p->y()==gh4->y()){
        ui->line2->show();
        now->stop();

        p->hide();
    }*/

    if ((p->collidesWithItem(gh1)||p->collidesWithItem(gh2)||p->collidesWithItem(gh3)||p->collidesWithItem(gh4))&&ppt==0){
        ui->line2->show();
        now->stop();

        p->hide();
    }

    if(p->collidesWithItem(gh1)&&ppt==2){
        gh1->setPos(-20,0);
        score+=200^(gn+1);
        ui->lcd->display(score);
        gn+=1;
    }
    if(p->collidesWithItem(gh2)&&ppt==2){
        gh2->setPos(-20,0);
        score+=200^(gn+1);
        ui->lcd->display(score);
        gn+=1;
    }
    if(p->collidesWithItem(gh3)&&ppt==2){
        gh3->setPos(-20,0);
        score+=200^(gn+1);
        ui->lcd->display(score);
        gn+=1;
    }
    if(p->collidesWithItem(gh4)&&ppt==2){
        gh4->setPos(-20,0);
        score+=200^(gn+1);
        ui->lcd->display(score);
        gn+=1;
    }





            qDebug()<<ppt;


}

void game::g1move()
{
    gggg = qrand()%4;
    //gg1=qrand()%4;
    //srand(6);
    gg2=random()%4;
    //srand(23);
    gg3=random()%2;
    //srand(66);
    gg4=random()%4;

}

void game::gggmove()
{

    ggg=qrand()%3;

}

void game::ptime()
{
    ppt=0;
    gn=0;
}


void game::stop(int q,int w)
{
    p->setPos(q,w);
}



game::~game()
{
    delete ui;
}













