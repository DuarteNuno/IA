#include "libraries.h"
#include "Map.h"

void random_vector(Map *m);
void order(Map *m);
void print_Path(Map *m);

bool accept(int actual_p,int neighbour_p,int temp);

int n_Intersections(vector<Point*> p);

vector<Point*> choose_opt(char opt, vector<vector<Point*>>* candidates,vector<Point*> best);

bool on_segment(Point* p1,Point* p2,Point* p3);

bool legal_intersect(Point* p1, Point* p2, Point* p3, Point* p4);

bool vectors_Intersect(Point* p1i, Point* p1f, Point* p2i, Point* p2f);

vector<vector<Point*>>* two_exchange(vector<Point*> p);

double perimeters(vector<Point*> v);

Point* ant_choose_point(Point* actual, vector<Point*> *points,double alpha,double beta);

double distance(Point *a, Point *b);