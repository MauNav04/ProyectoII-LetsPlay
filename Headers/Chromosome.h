//
// Created by mavros on 3/6/21.
//

#ifndef PROYECTOII_LETSPLAY_CHROMOSOME_H
#define PROYECTOII_LETSPLAY_CHROMOSOME_H


#include <array>
#include "Direction.h"

class Chromosome {

private:
    float fitness{};
    std::array<direction, 128> genes{};

public:
    Chromosome();

    explicit Chromosome(const std::array<direction, 128> &genes);

    bool operator < (const Chromosome &other) const {
        return  fitness < other.fitness;
    }

    float getFitness() const;

    void setFitness(float fitness);

    const std::array<direction, 128> &getGenes() const;

    void setGenes(const std::array<direction, 128> &genes);
};


#endif //PROYECTOII_LETSPLAY_CHROMOSOME_H
