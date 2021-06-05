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
    hidePiece();
    shuffle();
}

Puzzle::~Puzzle() = default;

void Puzzle::hidePiece() {
    puzzleMatrix[getNumRows() - 1][getNumColumns() - 1]->setDisplayed(false);
}

void Puzzle::setDirection(direction dir) {
    movedRow = emptyRow;
    movedColumn = emptyColumn;
    switch (dir) {
        case direction::UP:
            if (emptyRow < getNumRows() - 1) {
                movedRow++;
            }
            break;
        case direction::DOWN:
            if (emptyRow > 0) {
                movedRow--;
            }
            break;
        case direction::LEFT:
            if (emptyColumn < getNumColumns() - 1) {
                movedColumn++;
            }
            break;
        case direction::RIGHT:
            if (emptyColumn > 0) {
                movedColumn--;
            }
            break;
    }
}

void Puzzle::move(direction dir) {
    int row;
    int col;
    setDirection(dir);
    PuzzlePiece * movePiece = puzzleMatrix[movedRow][movedColumn];
    PuzzlePiece * emptyPiece = puzzleMatrix[emptyRow][emptyColumn];
    puzzleMatrix[emptyRow][emptyColumn] = movePiece;
    puzzleMatrix[movedRow][movedColumn] = emptyPiece;
    row = emptyRow;
    col = emptyColumn;
    emptyRow = movedRow;
    emptyColumn = movedColumn;
    movedRow = row;
    movedColumn = col;
}

void Puzzle::shuffle() {
    int times = 5;
    while (times > 0) {
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                move(moveRandom());
                while (i == puzzleMatrix[i][j]->getCorrectRow() && j == puzzleMatrix[i][j]->getCorrectColumn()) {
                    move(moveRandom());
                }
            }
        }
        times--;
    }
}

direction Puzzle::moveRandom() {
    std::random_device rd;
    std::uniform_int_distribution<size_t> distribution(0, ALL_DIRECTIONS.size() - 1);
    direction ranDir = ALL_DIRECTIONS[distribution(rd)];
    return ranDir;
}

float Puzzle::isSolved() {
    int correctRow;
    int correctCol;
    int score = 0;
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumColumns(); j++) {
            correctRow = puzzleMatrix[i][j]->getCorrectRow();
            correctCol = puzzleMatrix[i][j]->getCorrectColumn();
            if (correctRow == i && correctCol == j) {
                score++;
            }
        }
    }
    return score;
}

int Puzzle::getNumRows() {
    return sizeof puzzleMatrix / sizeof puzzleMatrix[0];
}

unsigned long Puzzle::getNumColumns() {
    return sizeof(puzzleMatrix[0]) / sizeof(puzzleMatrix[0][0]);
}

const std::array<std::array<PuzzlePiece *, 4>, 4> &Puzzle::getPuzzleMatrix() const {
    return puzzleMatrix;
}
