#include "Map.h"

Point::Point(int xcoord, int ycoord){
    x = xcoord;
    y = ycoord;

    visited=false;
};

void Point::Point_Print(){
    cout << "P("<< x<<","<< y <<")" <<endl;
    cout << endl;
}

Map::Map (int m) {
    MaxN = m;
};

void Map::Print_Points(){
    for(auto const& i : Points){
        i->Point_Print();
    }
}


bool Map::Contains(Point* p){
      for(auto const& i : this->Points){
        if((i->x==p->x)&&(i->y==p->y)){      
          return true;
        }
      }
      return false;
}
