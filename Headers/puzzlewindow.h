#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QDialog>
#include <QLabel>
#include "PuzzleGrid.h"
#include "GeneticSolver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class puzzlewindow; }
QT_END_NAMESPACE

class puzzlewindow : public QDialog
{
    Q_OBJECT

private:
    Ui::puzzlewindow *ui;
    QString textLabel;
    PuzzleGrid field = PuzzleGrid(true);
    GeneticSolver solver = GeneticSolver(field);
    std::array<direction, 128> solution;
    int numDirection = 0;
    QLabel* labels[4][4];

private slots:
    void on_previousButton_clicked();

    void on_nextButton_clicked();

public:
    puzzlewindow(QWidget *parent = nullptr);
    ~puzzlewindow();

    void initLabels();

};
#endif // PUZZLEWINDOW_H
