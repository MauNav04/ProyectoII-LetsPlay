#include <QApplication>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QRectF>
#include <QThread>
#include <QStyleOptionGraphicsItem>
#include "../Headers/BoardManger.h"
#include "../Headers/foosballwindow.h"

using namespace std;


void foosballwindow::show(int numPlayers, int formation, int balls) {

    //First thing Create a Scene
    auto * scene = new QGraphicsScene();

    auto * view = new QGraphicsView; //View is also a widget that makes the Scene and its elements visible, so we also must display it
    view->setScene(scene);

    //Deletes the scroll bars for the screen
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //shows the view
    view->show();
    //Sets new fixed size for the view
    view->setFixedSize(800,600);
    //Positions the scene on 0,0 and sets the size same as the view
    scene->setSceneRect(0,0,750,600);

    auto *BManager = new BoardManger(scene,numPlayers,formation,balls);

}