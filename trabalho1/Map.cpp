#include "Map.h"

Point::Point(int xcoord, int ycoord){
    x = xcoord;
    y = ycoord;
};

void Point::Print(){
    cout << "x="<< x <<endl;
    cout << "y="<< y <<endl;
    cout << endl;
}

Map::Map (int m) {
    MaxN = m;
};

void Map::PrintPoints(){
    for(auto const& i : Points){
        i->Print();
    }
}