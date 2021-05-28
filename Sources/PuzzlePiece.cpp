//
// Created by mavros on 26/5/21.
//

#include "../Headers/PuzzlePiece.h"

PuzzlePiece::PuzzlePiece(int xpos, int ypos) : xpos(xpos), ypos(ypos) {}

PuzzlePiece::~PuzzlePiece() = default;

bool PuzzlePiece::isDisplayed() const {
    return displayed;
}

void PuzzlePiece::setDisplayed(bool displayed) {
    PuzzlePiece::displayed = displayed;
}

int PuzzlePiece::getXpos() const {
    return xpos;
}

int PuzzlePiece::getYpos() const {
    return ypos;
}
