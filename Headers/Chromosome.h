//
// Created by mavros on 3/6/21.
//

#ifndef PROYECTOII_LETSPLAY_CHROMOSOME_H
#define PROYECTOII_LETSPLAY_CHROMOSOME_H


#include <array>
#include "Direction.h"

/**
 * Clase usada en el algoritmo genético que almacena movimientos como genes en un array y su fitness
 */
class Chromosome {

private:

    /**
     * Valor que dice qué tan cerca está el cromosoma de solucionar el rompecabezas
     */
    float fitness{};

    /**
     * Array con movimientos aleatorios (genes) utilizados para tratar de solucionar el rompecabezas
     */
    std::array<direction, 128> genes{};

public:

    /**
     * Constructor utilizado para inicializar cromosomas de manera simple introduciéndolos con un for en un array
     */
    Chromosome();

    /**
     * Constructor que pide la cantidad de movimientos que guarda el cromosoma
     * @param genes array de movimientos aleatorios
     */
    explicit Chromosome(const std::array<direction, 128> &genes);

    /**
     * Destructor del cromosoma
     */
    virtual ~Chromosome();

    /**
     * Método para organizar los cromosomas de acuerdo a su fitness
     * @param other
     * @return
     */
    bool operator < (const Chromosome &other) const {
        return  fitness < other.fitness;
    }

    /**
     * Getter del Fitness
     * @return valor del fitness
     */
    float getFitness() const;

    /**
     * Setter del fitness
     * @param fitness valor nuevo del fitness
     */
    void setFitness(float fitness);

    /**
     * Getter del array de movimientos
     * @return array de movimientos
     */
    const std::array<direction, 128> &getGenes() const;

};


#endif //PROYECTOII_LETSPLAY_CHROMOSOME_H
