//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLEPIECE_H
#define PROYECTOII_LETSPLAY_PUZZLEPIECE_H

/**
 * Clase de las piezas que se mueven en el rompecabezas
 */
class PuzzlePiece {

private:

    /**
     * Si es falso, significa que es el lugar donde se pueden hacer movimientos. Solo una pieza en el rompecabezas
     * puede tener este booleano falso
     */
    bool displayed;

    /**
     * Indica en qué fila debería de estar la pieza
     */
    int posRow;

    /**
     * Indica en qué columna debería de estar la pieza
     */
    int posColumn;

public:

    /**
     * Constructor de la pieza que requiere su posición correcta en su fila y columna respectivas
     * @param xpos Fila correcta
     * @param ypos Columna correcta
     */
    PuzzlePiece(int xpos, int ypos);

    /**
     * Destructor de la pieza
     */
    virtual ~PuzzlePiece();

    /**
     * Indica si la pieza es visible o no
     * @return visibilidad
     */
    bool isDisplayed() const;

    /**
     * Define la visibilidad de la pieza
     * @param displayed visibilidad
     */
    void setDisplayed(bool displayed);

    /**
     * Getter de la fila correcta del rompecabezas
     * @return fila correcta del rompecabezas
     */
    int getCorrectRow() const;

    /**
     * Getter de la columna correcta del rompecabezas
     * @return columna correcta del rompecabezas
     */
    int getCorrectColumn() const;
};


#endif //PROYECTOII_LETSPLAY_PUZZLEPIECE_H
