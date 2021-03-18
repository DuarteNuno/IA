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
        list<Point*> Points;
        list<Point*> ClosedList;//visited Points
        list<Point*> Path;

        Map (int m);
        void PrintPoints();
        bool Contains( Point* p);
};