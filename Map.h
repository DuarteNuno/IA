#include "libraries.h"

class Point{
    public:
        int x;
        int y;

        bool visited;

        Point *prev;
        Point *next;

        bool l1_visited;

        Point(int xcoord, int ycoord);
        void Point_Print();
        bool Compare(Point* p);
};

class Map{
    public:
        int MaxN; // l h
        vector<Point*> Points;
        vector<Point*> Openlist;
        vector<Point*> Closedlist;//visited Points
        vector<Point*> Path;
    

        //Point inicial

        Map (int m);
        void Print_Points();
        void Print_Vecs();
        void Print_Map();
        bool Contains( Point* p);

};
