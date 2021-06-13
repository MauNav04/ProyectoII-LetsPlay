#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QDialog>
#include <QLabel>
#include "PuzzleGrid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class puzzlewindow; }
QT_END_NAMESPACE

class puzzlewindow : public QDialog
{
    Q_OBJECT

private:
    Ui::puzzlewindow *ui;
    PuzzleGrid field = PuzzleGrid(true);
    QLabel* labels[4][4];

public:
    puzzlewindow(QWidget *parent = nullptr);
    ~puzzlewindow();

    void initLabels();

};
#endif // PUZZLEWINDOW_H
