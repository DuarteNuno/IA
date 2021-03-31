#include "Map.h"

Point::Point(int xcoord, int ycoord){
    x = xcoord;
    y = ycoord;

    visited=false;
};

void Point::Print(){
    cout << "P("<< x<<","<< y <<")" <<endl;
    cout << endl;
}

Directed_Line::Directed_Line(Point *i, Point *f){
  inicial=i;
  final=f;
}

Map::Map (int m) {
    MaxN = m;
};

void Map::PrintPoints(){
    for(auto const& i : Points){
        i->Print();
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