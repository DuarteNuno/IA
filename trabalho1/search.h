#include "libraries.h"
#include "Map.h"

void random_vector(Map *m);
void order(Map *m);
void print_Path(Map *m);
void nearest_Neighbour(Map *m);
//void permutation(Map *m);
//void perm(vector<Point*> list, int final);

double cross_Product(Vec* v1, Vec* v2);

bool on_segment(Point* p1,Point* p2,Point* p3);

bool vectors_Intersect(Vec* v1, Vec* v2);

void two_exchange(Map *m);