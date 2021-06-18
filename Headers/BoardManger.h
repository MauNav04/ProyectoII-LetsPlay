//
// Created by mauro on 6/10/21.
//

#ifndef LITTLESOCER_BOARDMANGER_H
#define LITTLESOCER_BOARDMANGER_H


#include <QString>
#include <QGraphicsScene>
#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include "ConectionManager.h"


class BoardManger: public QObject {
    Q_OBJECT
public:
    bool gamy;
    QGraphicsScene *superScene;
    QString respuestaServer;
    ConectionManager connManager;
    QJsonDocument jsonDoc;
    QJsonObject jsonObj;
    QString mensaje;
    QString tipoTrayectoria;
    int numeroCasilla;
    QList<QPoint> temp;
    int coordX;
    int coordY;


    BoardManger();
    BoardManger(QGraphicsScene *scene, int amountPlayers, int formationID, int cantidadBolas);
    void msleep(int msec);
    void setFormation(int amountPlayers, int formationID);
    void updateBoard(QString spaceToMove);
    QList<QString *> getBoard();
    void setBoard(QList<QString> *board);
    void draw(QGraphicsScene *scene);

    void PositionSelector();
    void ExtractPlayers();
    void ControllingButtons (QGraphicsScene *scene);
    QList<QString> updateBoard(QPoint spaceToMove);
    QList<QString> updatePath(QPoint spaceToMove);
    void GraphicUpdate(QGraphicsScene *scene, QList<QPoint> BallTrace);
    QPoint cambiarFormato(int numeroCasilla);


    bool GameLoop();

public slots:
    void btnClicked_N();
    void btnClicked_E();
    void btnClicked_S();
    void btnClicked_W();
    void btnClicked_NW();
    void btnClicked_NE();
    void btnClicked_SE();
    void btnClicked_SW();
    void btnClicked_Weak();
    void btnClicked_Normal();
    void btnClicked_Strong();
    void btnClicked_Shoot();
    void btnClicked_PathF();
    void btnClicked_CenterBall();


};


#endif //LITTLESOCER_BOARDMANGER_H
