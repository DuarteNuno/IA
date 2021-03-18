#include "search.h"


void random_Search(Map *m){
   // random_shuffle(m->Points.begin(),m->Points.end());
  // shuffle(m->Points.begin(),m->Points.end(),default_random_engine(0));
    order(m);
}

void order(Map *m){ 
    for(auto const& i : m->Points){ 
        Point *currentPoint = i;
        currentPoint->Print();
    }
}