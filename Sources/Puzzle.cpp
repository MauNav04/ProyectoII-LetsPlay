//
// Created by mavros on 26/5/21.
//

#include <random>
#include <bits/stdc++.h>
#include "../Headers/Puzzle.h"

Puzzle::Puzzle(bool isHard) : hard(isHard) {
    for (int i = 0; i < sizeof(puzzleMatrix) / sizeof(puzzleMatrix[0]); i++) {
        for (int j = 0; j < sizeof(puzzleMatrix[0]) / sizeof(puzzleMatrix[0][0]); j++) {
            puzzleMatrix[i][j] = new PuzzlePiece(i, j);
        }
    }
}

Puzzle::~Puzzle() = default;

void Puzzle::hidePiece() {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 3);
    emptyRow = distribution(rd);
    emptyColumn = distribution(rd);
    puzzleMatrix[emptyRow][emptyColumn]->setDisplayed(false);
}

void Puzzle::setDirection(direction dir) {
    moveRow = emptyRow;
    moveColumn = emptyColumn;
    switch (dir) {
        case direction::UP:
            if (emptyRow > 0) {
                moveRow--;
            }
            break;
        case direction::DOWN:
            if (emptyRow < sizeof(puzzleMatrix[0]) / sizeof(puzzleMatrix[0][0])) {
                moveRow++;
            }
            break;
        case direction::LEFT:
            if (emptyColumn > 0) {
                moveColumn--;
            }
            break;
        case direction::RIGHT:
            if (emptyColumn > sizeof(puzzleMatrix) / sizeof(puzzleMatrix[0])) {
                moveRow++;
            }
            break;
    }
}

void Puzzle::move(direction dir) {
    setDirection(dir);
    PuzzlePiece * movePiece = puzzleMatrix[moveRow][moveColumn];
    PuzzlePiece * emptyPiece = puzzleMatrix[emptyRow][emptyColumn];
    puzzleMatrix[emptyRow][emptyColumn] = movePiece;
    puzzleMatrix[moveRow][moveColumn] = emptyPiece;
    emptyRow = moveRow;
    emptyColumn = moveColumn;
}

PuzzlePiece Puzzle::getPuzzlePiece(int x, int y) {
    return *puzzleMatrix[x][y];
}

int Puzzle::getXempty() const {
    return emptyRow;
}

int Puzzle::getYempty() const {
    return emptyColumn;
}


