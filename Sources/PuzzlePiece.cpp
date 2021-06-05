//
// Created by mavros on 26/5/21.
//

#include "../Headers/PuzzlePiece.h"

PuzzlePiece::PuzzlePiece(int xpos, int ypos) : posRow(xpos), posColumn(ypos) {
    displayed = true;
}

PuzzlePiece::~PuzzlePiece() = default;

bool PuzzlePiece::isDisplayed() const {
    return displayed;
}

void PuzzlePiece::setDisplayed(bool displayed) {
    PuzzlePiece::displayed = displayed;
}

int PuzzlePiece::getCorrectRow() const {
    return posRow;
}

int PuzzlePiece::getCorrectColumn() const {
    return posColumn;
}
