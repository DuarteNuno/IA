#include "libraries.h"
class Line;
class Point{
    public:
        int x;
        int y;

        bool visited;

        Point *prev;
        Point *next;

        Line *l1;
        Line *l2;

        bool l1_visited;

        Point(int xcoord, int ycoord);
        void Point_Print();
        bool Compare(Point* p);
};

class Vec{
    public:
        Point* start;
        Point* finish;
        int x;
        int y;
        double size;
        bool intercepted;

        bool visited;

        Vec(Point* s, Point* f);
        void Vec_Print();
};

class Line{
    public:
        Vec* v1;
        Vec* v2;
        
        bool visited;

        Line(Vec* a, Vec* b);
};

class Map{
    public:
        int MaxN; // l h
        vector<Point*> Points;
        vector<Point*> Openlist;
        vector<Point*> Closedlist;//visited Points
        vector<Point*> Path;
        vector<Vec*> Links;
        vector<Line*> Lines;

        //Point inicial

        Map (int m);
        void Print_Points();
        void Print_Vecs();
        bool Contains( Point* p);
};
/*
class Candidates{
    public:
        vector<vector<Point*>> List_Candidate;
};
*/


