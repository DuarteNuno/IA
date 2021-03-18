#include <iostream>
#include <list>

using namespace std;

class Point{
    public:
        int x;
        int y;

        Point(int xcoord, int ycoord);
        void Print();
};

class Map{
    public:
        int MaxN; // l h
        list<Point*> Points;

        Map (int m);
        void PrintPoints();
};