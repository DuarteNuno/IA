#include "search.h"

/*
 *
 *props às ninas @patricia4vieira e @CatarinaSemInsta
 *
 */

int main(){
  
   
   /*  cout << "Tamanho do mapa:"<<endl;
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

         int x1,y1,x2,y2;
        cin >>x1;
        cin >>y1;


        Point* point = new Point(x1,y1); 
        
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

    cout<<endl;
    cout<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    //permutation(map);
    //nearest_Neighbour(map);
    two_exchange(map);
   // map->Print_Vecs();
    //print_Path(map);
   ------------------------------------------------------------------------------------- 
    */

    /* cout << "Primeiro  ponto "<<endl;
    int x1,y1,x2,y2;
    cin >>x1;
    cin >>y1;
    cin >>x2;
    cin >>y2;

    Point* p1 = new Point(x1,y1);
    Point* p2 = new Point(x2,y2);

   Vec v = Vec(p1,p2);
   cout << v.size << endl; */
   
    int mapsize;
    cin >>mapsize;
    Map *map = new Map(mapsize);

 
      int x1,y1,x2,y2,x3,y3,x4,y4; // 00 11 01 10
      cin >> x1>> y1;
      cin >> x2>> y2;
      cin >> x3>> y3;
      cin >> x4>> y4;
      Point* p1 = new Point(x1,y1);
      Point* p2 = new Point(x2,y2);
      Point* p3 = new Point(x3,y3);
      Point* p4 = new Point(x4,y4);
        map->Points.insert(map->Points.begin(),p1);
        map->Points.insert(map->Points.begin(),p2);
        map->Points.insert(map->Points.begin(),p3);
        map->Points.insert(map->Points.begin(),p4);

       //Vec* v1 = new Vec(p1,p2);
       //Vec* v2 = new Vec(p2,p3);
       //Vec* v3 = new Vec(p3,p4);
      // Vec* v4 = new Vec(p4,p1);

    //cout << cross_Product(v1,v2) << endl;
    //cout << on_segment(p1,p2,p3);
    cout<<"ola"<<endl;
    nearest_Neighbour(map);
    
    vector<vector<Point*>>* two_x = two_exchange(map->Path);
    cout<<"g"<<endl;
    for(int i = 0; i<two_x->size();i++){
      for(auto const& j :two_x[i]){
        for(auto const& k :j){
          k->Point_Print();
        }
      }
    }

    //print_Path(map);
    cout<<"xau"<<endl;



}