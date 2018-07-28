#ifndef GA_H_
#define GA_H_

#include <vector>

using namespace std;

typedef struct individual
{
	string genetic;
	int fitness;
} Individual;

const bool compareInd(Individual a, Individual b);

const int POPULATION_SIZE = 100;

vector<Individual> population;
vector<Individual> selection1;
vector<Individual> selection2;

string correct;

const string ga(const string solution, const double mutateRate);
void setSolution(const string solution);
const bool checkMutateRate(const double mutateRate); // 0 <= rate < 1
void initialization();
const int fitnessFunction(const string str);
void select();
void crossover();
void mutate(const double mutateRate); // swap random char to other position
void totalUpdateFitness();
void sortPopulation();
void kill();
void clearSelections();
const bool checkIsThereAnswer(); // fitness = 0 -> answer

const string generateRandomString(const int length);

#endif // GA_H_
