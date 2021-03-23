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

Line::Line (Vec* a, Vec* b){
    v1=a;
    v2=b;
};

void Map::Print_Points(){
    for(auto const& i : Points){
        i->Point_Print();
    }
}

void Map::Print_Vecs(){
    for(auto const& i : Links){
        i->Vec_Print();
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
    x=(f->x)-(s->x);
    y=(f->y)-(s->y);
};

void Vec::Vec_Print(){
    //cout<<size<<endl;
    //cout<<"x:"<<x<<endl;
    //cout<<"y:"<<y<<endl;
    start->Point_Print();
    cout << "->";
    finish->Point_Print();
}