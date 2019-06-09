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

namespace Ui {
class game;
}

class game : public QMainWindow
{
    Q_OBJECT


public:
    explicit game(QWidget *parent = nullptr);
    ~game();

    QGraphicsScene *scene;

    QPixmap board,pac,dot[244],g1,g2,g3,g4;
    QGraphicsPixmapItem *p,*d[244],*gh1,*gh2,*gh3,*gh4;
    QGraphicsTextItem *text;
    int i,r,k,n,t,m=0,f=0,score=0,dd[244],over=0,gg1,gg2,gg3,gg4;
    bool walk(int x,int y);
private:
    Ui::game *ui;
    //QTimer *mytime;
    QTimer *now,*gt1;

    QLCDNumber *lcd;

    // QWidget interface
protected:
    void keyPressEvent(QKeyEvent *event);

    void stop();

private slots:
    void move();
    void g1move();





};

#endif // GAME_H
