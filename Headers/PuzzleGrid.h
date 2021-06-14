//
// Created by mavros on 26/5/21.
//

#ifndef PROYECTOII_LETSPLAY_PUZZLEGRID_H
#define PROYECTOII_LETSPLAY_PUZZLEGRID_H


#include <array>
#include "PuzzlePiece.h"
#include "Direction.h"

class PuzzleGrid {

private:

    /**
     * Define la dificultad del tablero
     */
    bool hard;

    /**
     * Posición de la fila de la pieza movida anteriormente
     */
    int movedRow{};

    /**
     * Posición de la columna de la pieza movida anteriormente
     */
    int movedColumn{};

    /**
     * Posición de la fila del lugar sin pieza, donde hay movimiento
     */
    int emptyRow{};

    /**
     * Posición de la columna del lugar sin pieza, donde hay movimiento
     */
    int emptyColumn{};

    /**
     * Matriz que contiene la posición de las piezas del rompecabezas
     */
    std::array<std::array<PuzzlePiece *, 4>, 4> puzzleMatrix;

public:

    /**
     * Constructor que define la dificultad del rompecabezas
     * @param isHard dificultad del rompecabezas
     */
    explicit PuzzleGrid(bool isHard);

    /**
     * Destructor del rompecabezas
     */
    virtual ~PuzzleGrid();

    /**
     * Esconde la ñultima pieza del tablero, donde es posible hacer movimientos
     */
    void hidePiece();

    /**
     * Da las instrucciones correctas para mover el rompecabezas dependiento del movimiento que reciba
     * @param dir
     */
    void setDirection(direction dir);

    /**
     * Mueve las piezas del rompecabezas según el movimiento que recibió
     * @param dir
     */
    void move(direction dir);

    /**
     * Hace una gran cantidad de movimientos aleatorios que revuelven las piezas del tablero
     */
    void shuffle();

    /**
     * Retorna un tipo de movimiento aleatorio
     * @return movimiento aleatorio
     */
    static direction moveRandom();

    /**
     * Revisa si el rompecabezas estás solucionado, con las piezas en su posición correcta
     * @return Si el rompecabezas está solucionado, retorna true
     */
    float isSolved();

    int getMovedRow() const;

    int getMovedColumn() const;

    int getEmptyRow() const;

    int getEmptyColumn() const;


    /**
     * Retorna la cantidad de filas en el rompecabezas
     * @return número de filas en el rompecabezas
     */
    int getNumRows();

    /**
     * Retorna la cantidad de columnas en el rompecabezas
     * @return número de columnas en el rompecabezas
     */
    unsigned long getNumColumns();

    /**
     * Getter de la matriz del rompecabezas
     * @return matriz del rompecabezas
     */
    const std::array<std::array<PuzzlePiece *, 4>, 4> &getPuzzleMatrix() const;

};


#endif //PROYECTOII_LETSPLAY_PUZZLEGRID_H
