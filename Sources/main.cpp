#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../Headers/Puzzle.h"

int main(int argc, char *argv[]) {
    Puzzle p = new Puzzle(true);
    p.shufflePuzzle();
    std::cout << p.getXempty() << " " << p.getYempty() << std::endl;
    p.shufflePuzzle();
    std::cout << p.getXempty() << " " << p.getYempty() << std::endl;
    std::cout << p.getPuzzlePiece(0, 0).isDisplayed() << std::endl;
    std::cout << p.getPuzzlePiece(p.getXempty(), p.getYempty()).isDisplayed() << " " << std::endl;
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
