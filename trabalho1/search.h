#include "libraries.h"
#include "Map.h"

void random_vector(Map *m);
void order(Map *m);
void print_Path(Map *m);
void nearest_Neighbour(Map *m);
//void permutation(Map *m);
//void perm(vector<Point*> list, int final);

double cross_Product(int x1,int y1,int x2,int y2);

bool on_segment(Point* p1,Point* p2,Point* p3);

bool legal_intersect(Point* p1, Point* p2, Point* p3, Point* p4);

bool vectors_Intersect(Vec* v1, Vec* v2);

vector<vector<Point*>>* two_exchange(vector<Point*> p);