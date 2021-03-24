#include "libraries.h"
#include "Map.h"

void random_vector(Map *m);
void order(Map *m);
void print_Path(Map *m);
void nearest_Neighbour(Map *m);

double cross_Product(int x1,int y1,int x2,int y2);

bool on_segment(Point* p1,Point* p2,Point* p3);

bool legal_intersect(Point* p1, Point* p2, Point* p3, Point* p4);

bool vectors_Intersect(Point* p1i, Point* p1f, Point* p2i, Point* p2f);

vector<vector<Point*>>* two_exchange(vector<Point*> p);

vector<Point*> hill_climbing(char opt, vector<vector<Point*>>* candidates);

double perimeters(vector<Point*> v);