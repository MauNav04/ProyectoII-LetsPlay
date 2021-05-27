//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLEPIECE_H
#define PROYECTOII_LETSPLAY_PUZZLEPIECE_H


class PuzzlePiece {
public:
    PuzzlePiece(int xpos, int ypos);

    virtual ~PuzzlePiece();

private:
    int xpos;
    int ypos;
};


#endif //PROYECTOII_LETSPLAY_PUZZLEPIECE_H
