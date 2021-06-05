//
// Created by mavros on 3/6/21.
//

#include <algorithm>
#include "../Headers/Chromosome.h"

Chromosome::Chromosome() {}

Chromosome::Chromosome(const std::array<direction, 128> &genes) : genes(genes) {}

float Chromosome::getFitness() const {
    return fitness;
}

void Chromosome::setFitness(float fitness) {
    Chromosome::fitness = fitness;
}

const std::array<direction, 128> &Chromosome::getGenes() const {
    return genes;
}

void Chromosome::setGenes(const std::array<direction, 128> &genes) {
    Chromosome::genes = genes;
}
