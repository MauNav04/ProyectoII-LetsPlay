//
// Created by mavros on 26/5/21.
//

#include <random>
#include <bits/stdc++.h>
#include "../Headers/PuzzleGrid.h"

PuzzleGrid::PuzzleGrid(bool isHard) : hard(isHard) {
    for (int i = 0; i < getNumRows(); i++) {
        for (int j = 0; j < getNumColumns(); j++) {
            puzzleMatrix[i][j] = new PuzzlePiece(i, j);
        }
    }
    hidePiece();
    shuffle();
}

PuzzleGrid::~PuzzleGrid() = default;

void PuzzleGrid::hidePiece() {
    puzzleMatrix[getNumRows() - 1][getNumColumns() - 1]->setDisplayed(false);
}

void PuzzleGrid::setDirection(direction dir) {
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

void PuzzleGrid::move(direction dir) {
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

void PuzzleGrid::shuffle() {
    //originalmente times = 5
    int times = 5;
    while (times > 0) {
        for (int i = 0; i < getNumRows(); i++) {
            for (int j = 0; j < getNumColumns(); j++) {
                move(moveRandom());
//                while (i == puzzleMatrix[i][j]->getCorrectRow() && j == puzzleMatrix[i][j]->getCorrectColumn()) {
//                    move(moveRandom());
//                }
            }
        }
        times--;
    }
}

direction PuzzleGrid::moveRandom() {
    std::random_device rd;
    std::uniform_int_distribution<size_t> distribution(0, ALL_DIRECTIONS.size() - 1);
    direction ranDir = ALL_DIRECTIONS[distribution(rd)];
    return ranDir;
}

float PuzzleGrid::isSolved() {
    int correctRow;
    int correctCol;
    float score = 0;
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

int PuzzleGrid::getNumRows() {
    return sizeof puzzleMatrix / sizeof puzzleMatrix[0];
}

unsigned long PuzzleGrid::getNumColumns() {
    return sizeof(puzzleMatrix[0]) / sizeof(puzzleMatrix[0][0]);
}

int PuzzleGrid::getMovedRow() const {
    return movedRow;
}

int PuzzleGrid::getMovedColumn() const {
    return movedColumn;
}

int PuzzleGrid::getEmptyRow() const {
    return emptyRow;
}

int PuzzleGrid::getEmptyColumn() const {
    return emptyColumn;
}

const std::array<std::array<PuzzlePiece *, 4>, 4> &PuzzleGrid::getPuzzleMatrix() const {
    return puzzleMatrix;
}
