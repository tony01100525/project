#include "mainwindow.h"
#include "ui_mainwindow.h"

    game *gw;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    gw= new game;
    gw->show();
    hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    app->quit();
}
