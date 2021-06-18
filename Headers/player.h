//
// Created by mauro on 6/3/21.
//

#ifndef LITTLESOCER_PLAYER_H
#define LITTLESOCER_PLAYER_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class player : public QGraphicsItem{
public:
    player();

    QRectF boundingPlayer() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *OPTION, QWidget *widget);


};


#endif //LITTLESOCER_PLAYER_H
