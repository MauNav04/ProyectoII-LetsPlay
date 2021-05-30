//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLEPIECE_H
#define PROYECTOII_LETSPLAY_PUZZLEPIECE_H


class PuzzlePiece {

private:
    bool displayed = true;
    int posRow;
    int posColumn;

public:
    PuzzlePiece();

    PuzzlePiece(int xpos, int ypos);

    virtual ~PuzzlePiece();

    bool isDisplayed() const;

    void setDisplayed(bool displayed);

    int getXpos() const;

    int getYpos() const;
};


#endif //PROYECTOII_LETSPLAY_PUZZLEPIECE_H
