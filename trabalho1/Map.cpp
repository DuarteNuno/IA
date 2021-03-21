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

Vec::Vec(Point* s, Point* f){
    start=s;
    finish=f;
    size=sqrt(((f->x-s->x)*(f->x-s->x))+((f->y-s->y)*(f->y-s->y)));
    intercepted=false;
};

void Vec::Vec_Print(){
    cout<<size<<endl;
}