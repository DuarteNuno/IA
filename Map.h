#include "libraries.h"

class Point{
    public:
        int x;
        int y;

        Point *prev;
        Point *next;

        Point(int xcoord, int ycoord);
        void Print();
        bool Compare(Point* p);
};

class Map{
    public:
        int MaxN; // l h
        vector<Point*> Points;
        vector<Point*> Closedvector;//visited Points
        vector<Point*> Path;

        Map (int m);
        void PrintPoints();
        bool Contains( Point* p);
};