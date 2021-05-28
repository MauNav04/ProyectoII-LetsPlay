//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLE_H
#define PROYECTOII_LETSPLAY_PUZZLE_H


#include "PuzzlePiece.h"

class Puzzle {

private:
    bool hard;
    int xempty;
    int yempty;
    PuzzlePiece puzzleMatrix [4][4] = {
            {PuzzlePiece(0, 0), PuzzlePiece(0, 1), PuzzlePiece(0, 2), PuzzlePiece(0, 3)},
            {PuzzlePiece(1, 0), PuzzlePiece(1, 1), PuzzlePiece(1, 2), PuzzlePiece(1, 3)},
            {PuzzlePiece(2, 0), PuzzlePiece(2, 1), PuzzlePiece(2, 2), PuzzlePiece(2, 3)},
            {PuzzlePiece(3, 0), PuzzlePiece(3, 1), PuzzlePiece(3, 2), PuzzlePiece(3, 3)}
    };

public:
    Puzzle(bool isHard);

    virtual ~Puzzle();

    void hidePiece();

    PuzzlePiece getPuzzlePiece(int x, int y);

    int getXempty() const;

    int getYempty() const;

};


#endif //PROYECTOII_LETSPLAY_PUZZLE_H
