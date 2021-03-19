#include "search.h"
#include <random>
#include <algorithm>
#include <iterator>

void random_vector(Map *m){
    random_shuffle(m->Points.begin(), m->Points.end());
    m->PrintPoints();
}

void order(Map *m){ 
    m->PrintPoints();
}