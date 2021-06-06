#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../Headers/Puzzle.h"
#include "../Headers/GeneticSolver.h"

int main(int argc, char *argv[]) {
    Puzzle p = Puzzle(true);
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
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
