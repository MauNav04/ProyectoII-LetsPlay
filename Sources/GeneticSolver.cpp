//
// Created by mavros on 1/6/21.
//

#include <vector>
#include <array>
#include <algorithm>
#include <random>
#include "../Headers/GeneticSolver.h"

GeneticSolver::GeneticSolver(const Puzzle& puzzleMatrix) : originalPuzzle(puzzleMatrix), demoPuzzle(puzzleMatrix) {}

GeneticSolver::~GeneticSolver() = default;

std::array<direction, 128> GeneticSolver::solve() {
    std::array<direction, 128> individual{};
    createInitialPopulation();
    while (demoPuzzle.isSolved() < 16) {
        demoPuzzle = originalPuzzle;
        defineFitness();
        select();
        crossover();
        for (auto chrom : genome) {
            for (auto gene : chrom->getGenes()) {
                demoPuzzle.move(gene);
                if (demoPuzzle.isSolved() == 16) {
                    individual = chrom->getGenes();
                    return individual;
                }
            }
        }
    }
    return individual;
}

void GeneticSolver::createInitialPopulation() {
    std::array<direction, 128> genes{};
    int initialPopulaiton = 0;
    while (initialPopulaiton < 256) {
        for (int i = 0; i < genes.max_size(); i++) {
            genes[i] = Puzzle::moveRandom();
        }
        genome.push_back(new Chromosome(genes));
        initialPopulaiton++;
    }
}

void GeneticSolver::defineFitness() {
    float fitness;
    bool streak;
    float bonus = 0;
    int correctRow;
    int correctCol;
    for (Chromosome * chrom : genome) {
        for (direction gene : chrom->getGenes()) {
            demoPuzzle.move(gene);
//            if (chrom->getFitness() < demoPuzzle.isSolved()) {
            fitness = demoPuzzle.isSolved();
//            }
//            for (int i = 0; i < demoPuzzle.getNumRows(); i++) {
//                for (int j = 0; j < demoPuzzle.getNumColumns(); j++) {
//                    correctRow = demoPuzzle.getPuzzleMatrix()[i][j]->getCorrectRow();
//                    correctCol = demoPuzzle.getPuzzleMatrix()[i][j]->getCorrectColumn();
//                    if (correctRow == i && correctCol == j) {
//                        if (streak) {
//                            bonus += 0.1;
//                        }
//                        streak = true;
//                    } else {
//                        streak = false;
//                    }
//                }
//            }
//            fitness += bonus;
            chrom->setFitness(fitness);
        }
        demoPuzzle = originalPuzzle;
    }
}

void GeneticSolver::select() {
    std::sort(std::begin(genome), std::end(genome), [](auto& l, auto& r) -> bool {
        return l->getFitness() > r->getFitness();
    } );
    while (genome.size() > 64) {
        genome.pop_back();
    }
}

void GeneticSolver::crossover() {
    std::random_device rd;
    std::array<direction, 128> parent1{};
    std::array<direction, 128> parent2{};
    std::array<direction, 128> child{};
    int cut;
    std::uniform_int_distribution<size_t> percentage(0, 64);
    while (genome.size() < 128) {
        std::uniform_int_distribution<size_t> distribution(0, genome.size() - 1);
        parent1 = genome[distribution(rd)]->getGenes();
        parent2 = genome[distribution(rd)]->getGenes();
        cut = distribution(rd);
        for (int i = 0; i < cut; i++) {
            child[i] = parent1[i];
        }
        for (int i = cut; i < parent2.size(); i++) {
            child[i] = parent2[i];
        }
        if (percentage(rd) == 32) {
            child = mutation(child);
        }
        genome.push_back(new Chromosome(child));
    }
}

std::array<direction, 128> GeneticSolver::mutation(std::array<direction, 128> child) {
    std::random_device rd;
    std::uniform_int_distribution<size_t> distributionInt(0, child.size() - 1);
    std::uniform_int_distribution<size_t> distributionDir(0, ALL_DIRECTIONS.size() - 1);
    int randGene = distributionInt(rd);
    direction randDir = ALL_DIRECTIONS[distributionDir(rd)];
    child[randGene] = randDir;
    return child;
}
