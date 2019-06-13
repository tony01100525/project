#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTime>
#include <QLCDNumber>
#include <QGraphicsItem>
#include "ghost1.h"
#include "ghost2.h"
#include "ghost3.h"
#include "ghost4.h"

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT


public:
    explicit game(QWidget *parent = nullptr);
    ~game();
    ghost4 ghost44;
    ghost3 ghost33;
    ghost2 ghost22;
    ghost1 ghost11;

    QGraphicsScene *scene;

    QPixmap board,pac,dot[244],g1,g2,g3,g4,power[4],g5;
    QGraphicsPixmapItem *p,*d[244],*gh1,*gh2,*gh3,*gh4,*pow[4];
    QGraphicsTextItem *text;
    int i,r,k,n,t,m=0,f=0,score=0,dd[244],over=0,gg1=1,gg2,gg3,gg4,ggg,gggg,th=0,c=0,P=0,pp[4],ppt=0,gn=0;
    bool walk(int x,int y);
    bool cantwalk(int x,int y);
private:
    Ui::game *ui;
    //QTimer *mytime;
    QTimer *now,*gt1,*gt2,*pt;

    QLCDNumber *lcd;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

    void stop(int q,int w);

private slots:
    void move();
    void g1move();
    void gggmove();
    void ptime();








};

#endif // GAME_H
