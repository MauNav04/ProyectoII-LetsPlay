//
// Created by mavros on 1/6/21.
//

#ifndef PROYECTOII_LETSPLAY_GENETICSOLVER_H
#define PROYECTOII_LETSPLAY_GENETICSOLVER_H


#include "Puzzle.h"
#include "Chromosome.h"

class GeneticSolver {

private:
    std::vector<Chromosome*> genome;
    Puzzle originalPuzzle;
    Puzzle demoPuzzle;

public:
    explicit GeneticSolver(const Puzzle& puzzleMatrix);

    virtual ~GeneticSolver();

    std::array<direction, 128> solve();

    void select();

    void createInitialPopulation();

    void crossover();

    std::array<direction, 128> mutation(std::array<direction, 128> array);

    void defineFitness();
};


#endif //PROYECTOII_LETSPLAY_GENETICSOLVER_H
