//
// Created by mavros on 26/5/21.
//

#include <random>
#include "../Headers/Puzzle.h"

Puzzle::Puzzle(bool isHard) : hard(isHard) {}

Puzzle::~Puzzle() = default;

void Puzzle::hidePiece() {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 3);
    xempty = distribution(rd);
    yempty = distribution(rd);
    puzzleMatrix[xempty][yempty].setDisplayed(false);
}

PuzzlePiece Puzzle::getPuzzlePiece(int x, int y) {
    return puzzleMatrix[x][y];
}

int Puzzle::getXempty() const {
    return xempty;
}

int Puzzle::getYempty() const {
    return yempty;
}
