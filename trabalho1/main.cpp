#include "search.h"

int main(){
    
    cout << "Tamanho do mapa:"<<endl;
    int mapsize;
    cin >>mapsize;
    Map *map = new Map(mapsize);

    cout << "Numero de pontos:"<<endl;
    int number_points;
    cin >> number_points;
    
    for(int i=0; i<number_points; ++i){

        int r1=rand()%(mapsize+1);//numero 0 -m
        int r2=rand()%(mapsize+1);

        
        
        int xsign = rand()%2;//sinal
		int ysign = rand()%2;
		
		if(xsign) r1*= -1;//atribuir sinal
		if(ysign) r2*= -1;

        //cout<<r1 << "-" << r2<<endl;

        //cout<<endl;
       // cout<<"create point"<<endl;
       // cout<<endl;

        Point *point = new Point(r1,r2);

        //cout<<r1 << "-" << r2<<endl;

        //map->Contains(point) ? --i : map->Points.push_front(point);
        
        if(map->Contains(point)){
            //cout<<"iguais"<<endl;
            i--;
        }
        else{ 
            map->Points.insert(map->Points.begin(),point);
        }
    }
    //map->PrintPoints();
    order(map);
    random_vector(map);
}