#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <random>

#include "ga.h"

using namespace std;

const bool compareInd(Individual a, Individual b)
{
	return a.fitness < b.fitness;
}

const string ga(const string solution, const double mutateRate)
{
	setSolution(solution);
	checkMutateRate(mutateRate);
	
	string answer;
	
	initialization();
	
	while(checkIsThereAnswer() != true)
	{
		select();
		crossover();
		mutate(mutateRate);
		totalUpdateFitness();
		sortPopulation();
		kill();
		clearSelections();
		cout << population[0].genetic << ": " << population[0].fitness << endl;
	}
	
	sortPopulation();
	Individual ans = population[0];
	
	return answer;
}

void setSolution(const string solution)
{
	correct = solution;
}

const bool checkMutateRate(const double mutateRate)
{
	bool re = false;
	
	if(mutateRate >= 0 && mutateRate < 1)
	{
		re = true;
	}
	
	return re;
}

void initialization()
{
	for(int i = 0; i < POPULATION_SIZE; i++)
	{
		Individual indiv;
		indiv.genetic = generateRandomString(correct.size());
		indiv.fitness = fitnessFunction(indiv.genetic);
		population.push_back(indiv);
	}
}

const int fitnessFunction(const string str)
{
	int re = 0;
	
	for(int i = 0; i < correct.size(); i++)
	{
		re += abs(str[i] - correct[i]);
	}
	
	return re;
}

void select()
{
	random_device rd;
	mt19937 g(rd());
	
	for(int i = 0; i < POPULATION_SIZE/4; i++) // select to 1
	{
		shuffle(population.begin(), population.end(), g);
		//cout << population[0].genetic << endl;
		selection1.push_back(population[0]);
	}
	for(int i = 0; i < POPULATION_SIZE/4; i++) // select to 2
	{
		shuffle(population.begin(), population.end(), g);
		selection2.push_back(population[0]);
	}
}

void crossover()
{
	random_device rd;
	for(int i = 0; i < POPULATION_SIZE/4; i++)
	{
		int cutPosition = rd() % (correct.size()-1);
		Individual indiv1;
		indiv1.genetic = selection1[i].genetic.substr(0, cutPosition) + selection2[i].genetic.substr(cutPosition, correct.size());
		indiv1.fitness = fitnessFunction(indiv1.genetic);
		population.push_back(indiv1);
		Individual indiv2;
		indiv2.genetic = selection2[i].genetic.substr(0, cutPosition) + selection1[i].genetic.substr(cutPosition, correct.size());
		indiv2.fitness = fitnessFunction(indiv2.genetic);
		population.push_back(indiv2);
	}
}

void mutate(const double mutateRate)
{
	random_device rd;
	//cout << rd() << endl;
}

void totalUpdateFitness()
{
	for(int i = 0; i < population.size(); i++)
	{
		population[i].fitness = fitnessFunction(population[i].genetic);
	}
}

void sortPopulation()
{
	sort(population.begin(), population.end(), compareInd);
}

void kill()
{
	for(int i = 0; i < POPULATION_SIZE/2; i++)
	{
		population.pop_back();
	}
}

void clearSelections()
{
	selection1.clear();
	selection2.clear();
}

const bool checkIsThereAnswer()
{
	bool re = false;
	
	for(int i = 0; i < POPULATION_SIZE; i++)
	{
		if(population[i].fitness == 0)
		{
			re = true;
			break;
		}
	}
	
	return re;
}

const string generateRandomString(const int length)
{
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	random_device rd;
	mt19937 g(rd());
	std::shuffle(alpha.begin(), alpha.end(), g);
	return alpha.substr(0, length);
}
