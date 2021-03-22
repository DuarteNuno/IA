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

        
        //int r1=rand()%(mapsize+1);//numero 0 -m
        //int r2=rand()%(mapsize+1);

        
        
        //int xsign = rand()%2;//sinal
		//int ysign = rand()%2;
		
		//if(xsign) r1*= -1;//atribuir sinal
		//if(ysign) r2*= -1;

        //cout<<r1 << "-" << r2<<endl;

        //cout<<endl;
       // cout<<"create point"<<endl;
       // cout<<endl;

        int x1,y1,x2,y2;
        cin >>x1;
        cin >>y1;


        Point* point = new Point(x1,y1);
        
        //Point *point = new Point(r1,r2);

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

   /*  for(auto const& i :map->Points){
         for(auto const& j :map->Points){   
             if(i!=j){ 
                Vec* v = new Vec(i,j);
                map->Links.push_back(v);
                v->Vec_Print();
            }
        }
    } */

    //map->PrintPoints();
    order(map);

    cout<<endl;
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    //permutation(map);
    //nearest_Neighbour(map);
    two_exchange(map);
    map->Print_Vecs();
    print_Path(map);

    cout << "Primeiro  ponto "<<endl;
    int x1,y1,x2,y2;
    cin >>x1;
    cin >>y1;
    cin >>x2;
    cin >>y2;

    Point* p1 = new Point(x1,y1);
    Point* p2 = new Point(x2,y2);

   Vec v = Vec(p1,p2);
   cout << v.size << endl;

}