#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "../Headers/Puzzle.h"

int main(int argc, char *argv[]) {
    Puzzle p = new Puzzle(true);
    p.hidePiece();
    p.move(direction::LEFT);
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
