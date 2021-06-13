#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../Headers/PuzzleGrid.h"
#include "../Headers/GeneticSolver.h"
#include "../Headers/puzzlewindow.h"

int main(int argc, char *argv[]) {
    PuzzleGrid p = PuzzleGrid(true);
    p.move(direction::LEFT);
    GeneticSolver gs = GeneticSolver(p);
    std::array<direction, 128> solution = gs.solve();
    for (auto & i : solution) {
        p.move(i);
        if (p.isSolved() == 16) {
            break;
        }
    }
    QApplication a(argc, argv);
    puzzlewindow w;
    w.show();
    return a.exec();
}
