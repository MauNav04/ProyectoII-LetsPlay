//
// Created by mavros on 1/6/21.
//

#ifndef PROYECTOII_LETSPLAY_GENETICSOLVER_H
#define PROYECTOII_LETSPLAY_GENETICSOLVER_H


#include "PuzzleGrid.h"
#include "Chromosome.h"

/**
 * Clase que soluciona al rompecabezas con el algoritmo genético
 */
class GeneticSolver {

private:

    /**
     * Vector con cromosomas qeu representa la población total
     */
    std::vector<Chromosome*> genome;

    /**
     * Romprecabezas utilizado como referencia para reiniciar el rompecabezas de prueba
     */
    PuzzleGrid originalPuzzle;

    /**
     * Rombecabezas que tratan de solucionar los cromosomas
     */
    PuzzleGrid demoPuzzle;

public:

    /**
     * Constructor que recibe el rompecabezas a resolver
     * @param puzzleMatrix rompecabezas a resolver
     */
    explicit GeneticSolver(const PuzzleGrid& puzzleMatrix);

    /**
     * Destructor del solucionador
     */
    virtual ~GeneticSolver();

    /**
     * Contiene lso diferentes pasos del algoritmo genético y los encicla hasta obtener una solución
     * @return cromosoma con la solución del rompecabezas
     */
    std::array<direction, 128> solve();

    /**
     * Crea la población inicial del algoritmo genético
     */
    void createInitialPopulation();

    /**
     * Organiza a los cromosomas de acuerdo a su fitness y elimina la mitad de los cromosomas con el fitness más pequeño
     */
    void select();

    /**
     * Define la fórmula de fitness, que les asigna puntos dependiendo de cúantas piezas coloque correctamente en el
     * tablero y les da un bonus si hay una fila o columna solucionada
     */
    void defineFitness();

//    int fitnessBonus(int check);

/**
 * Cruza a los cromosomas con mayor fitness
 */
    void crossover();

    /**
     * Muta a los hijos cambiando un gen cualquiera con otro gen aleatorio
     * @param array hijo a modificar
     * @return hijo modificado
     */
    std::array<direction, 128> mutation(std::array<direction, 128> array);
};


#endif //PROYECTOII_LETSPLAY_GENETICSOLVER_H
