#include<bits/stdc++.h>
using namespace std;

const int N = 8; 

struct Chromosome {
    vector<int> queens;
    int fitness;

    Chromosome() : fitness(0) {
        queens.resize(N);
        for (int i = 0; i < N; ++i) {
            queens[i] = rand() % N;
        }
        calculateFitness();
    }

    void calculateFitness() {
        fitness = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (queens[i] != queens[j] && abs(i - j) != abs(queens[i] - queens[j])) {
                    fitness++;
                }
            }
        }
    }
};

Chromosome crossover(const Chromosome& parent1, const Chromosome& parent2) {
    Chromosome child;
    int crossoverPoint = rand() % N;
    for (int i = 0; i < crossoverPoint; ++i) {
        child.queens[i] = parent1.queens[i];
    }
    for (int i = crossoverPoint; i < N; ++i) {
        child.queens[i] = parent2.queens[i];
    }
    child.calculateFitness();
    return child;
}

void mutate(Chromosome& chromosome) {
    int mutationPoint = rand() % N;
    chromosome.queens[mutationPoint] = rand() % N;
    chromosome.calculateFitness();
}

Chromosome tournamentSelection(const vector<Chromosome>& population) {
    const int tournamentSize = 3;
    Chromosome bestParent;
    bestParent.fitness = -1;
    for (int i = 0; i < tournamentSize; ++i) {
        Chromosome candidate = population[rand() % population.size()];
        if (candidate.fitness > bestParent.fitness) {
            bestParent = candidate;
        }
    }
    return bestParent;
}

int main() {
    srand(time(nullptr));

    const int populationSize = 100;
    const int generations = 100;
    int ans = -100000000;

    vector<Chromosome> population(populationSize);
    
    int gen;
    for (gen = 0; gen < generations; ++gen) {
        sort(population.begin(), population.end(), [](const Chromosome& a, const Chromosome& b) {
            return a.fitness > b.fitness;
        });

        
        ans = max(ans,population[0].fitness);

        vector<Chromosome> newPopulation;
        for (int i = 0; i < populationSize; ++i) {
            Chromosome parent1 = tournamentSelection(population);
            Chromosome parent2 = tournamentSelection(population);
            Chromosome child = crossover(parent1, parent2);
            if (rand() % 100 < 5) {
                mutate(child);
            }
            newPopulation.push_back(child);
        }

        population = newPopulation;
        if(N*(N-1)/2==ans)break;
    }
    if(N*(N-1)/2==ans)cout << "Final Solution is found.\n";
    cout << "Maximum finess "<< ans << " found after "<< gen << " generations." << endl;
    return 0;
}
