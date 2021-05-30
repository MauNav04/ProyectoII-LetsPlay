//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLE_H
#define PROYECTOII_LETSPLAY_PUZZLE_H


#include "PuzzlePiece.h"
#include "Direction.h"

class Puzzle {

private:
    bool hard;
    int moveRow{};
    int moveColumn{};
    int emptyRow{};
    int emptyColumn{};
    PuzzlePiece * puzzleMatrix [4][4];

public:
    Puzzle(bool isHard);

    virtual ~Puzzle();

    void hidePiece();

    void setDirection(direction dir);

    void move(direction dir);

    PuzzlePiece getPuzzlePiece(int x, int y);

    int getXempty() const;

    int getYempty() const;

};


#endif //PROYECTOII_LETSPLAY_PUZZLE_H
