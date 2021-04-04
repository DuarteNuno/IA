#include "util.h"

extern double pheromones[MAX][MAX];

void nearest_Neighbour(Map *m);

vector<Point*> hill_climbing(char opt, vector<Point*> candidates);

vector<Point*> simulated_annealing(vector<Point*> inicial);

vector<Point*> ant_colony(vector<Point*> Points);