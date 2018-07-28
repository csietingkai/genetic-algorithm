# Genetic Algorithm
Author: Ting-Kai Hu

Today Date: 2018-06-19

## Abstract
This is a simple practice for understand Genetic Algorithm.

To understand more about Genetic Algorithm : https://en.wikipedia.org/wiki/Genetic_algorithm

Basically I have done useing a string as genetic to find out the answer.

## Usage
### ga.cpp, ga.h
 ```
 // genetic algorithm startint function named "ga(bestsolution, mutateRate) return answer" as following code
 string answer = ga(keyword, 0.005);
 ```
 Step 1: we initialize the group of individual, which we test it as string.
 
 Step 2: select two parts of individual as parents.
 
 Step 3: crossover two sub group and create two new sub group of child.
 
 Step 4: according to mutate rate to decide mutate or not.
 
 Step 5: add to original whole group and update fitness value.
 
 Step 6: go to Step2 again.
