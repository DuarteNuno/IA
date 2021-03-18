#include <iostream>
#include <list>

using namespace std;

class Point{
    public:
        int x;
        int y;

        Point(int xcoord, int ycoord){
            x = xcoord;
            y = ycoord;
        };
        void Print(){
            cout << "x="<< x <<endl;
            cout << "y="<< y <<endl;
            cout << endl;
        }
};

class Map{
    public:
        int MaxN; // l h
        list<Point*> Points;

    Map (int m) {
        MaxN = m;
    };

    void PrintPoints(){
        for(auto const& i : Points){
            i->Print();
        }
    }
};

int main(){
    cout << "Tamanho do mapa"<<endl;
    int mapsize;
    cin >>mapsize;
    Map *map = new Map(mapsize);

    cout << "Numero de pontos"<<endl;
    int number_points;
    cin >> number_points;
    
    for(int i=0; i<number_points; ++i){
        int r1,r2;
        r1=rand()%(mapsize+1);//numero 0 -m
        r2=rand()%(mapsize+1);
        
        int xsign = rand()%2;//sinal
		int ysign = rand()%2;
		
		if(xsign) r1*= -1;//atribuir sinal
		if(ysign) r2*= -1;

        Point *point = new Point(r1,r2);
        map->Points.push_front(point);
    }
    map->PrintPoints();
}