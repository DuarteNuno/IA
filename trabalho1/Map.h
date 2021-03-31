#include "libraries.h"

class Point{
    public:
        int x;
        int y;

        bool visited;

        Point *prev;
        Point *next;

        Point(int xcoord, int ycoord);
        void Print();
        bool Compare(Point* p);
};

class Directed_Line{
    public:
        Point *inicial;
        Point *final;
        bool intersected;
};



class Map{
    public:
        int MaxN; // l h
        vector<Point*> Points;
        vector<Point*> Openlist;
        vector<Point*> Closedlist;//visited Points
        vector<Point*> Path;
        vector<Directed_Line> lines;

        Map (int m);
        void PrintPoints();
        bool Contains( Point* p);
};