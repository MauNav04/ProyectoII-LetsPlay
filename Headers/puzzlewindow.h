//
// Created by mavros on 6/6/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLEWINDOW_H
#define PROYECTOII_LETSPLAY_PUZZLEWINDOW_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class puzzlewindow; }
QT_END_NAMESPACE

class puzzlewindow : public QWidget {
Q_OBJECT

public:
    explicit puzzlewindow(QWidget *parent = nullptr);

    ~puzzlewindow() override;

private:
    Ui::puzzlewindow *ui;
};


#endif //PROYECTOII_LETSPLAY_PUZZLEWINDOW_H
