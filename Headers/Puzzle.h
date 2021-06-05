//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLE_H
#define PROYECTOII_LETSPLAY_PUZZLE_H


#include <array>
#include "PuzzlePiece.h"
#include "Direction.h"

class Puzzle {

private:
    bool hard;
    int movedRow{};
    int movedColumn{};
    int emptyRow{};
    int emptyColumn{};
    std::array<std::array<PuzzlePiece *, 4>, 4> puzzleMatrix;

public:
    explicit Puzzle(bool isHard);

    virtual ~Puzzle();

    void hidePiece();

    void setDirection(direction dir);

    void move(direction dir);

    void shuffle();

    static direction moveRandom();

    float isSolved();

    int getNumRows();

    unsigned long getNumColumns();

    const std::array<std::array<PuzzlePiece *, 4>, 4> &getPuzzleMatrix() const;
};


#endif //PROYECTOII_LETSPLAY_PUZZLE_H
