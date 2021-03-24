#include "search.h"
/*
 *
 *Agradecemos a ajuda das meninas @Patricia Vieira e @Catarina Teixeira
 *
 */
int main(){
  cout << "Qual o tamanho do mapa:"<<endl;
  int mapsize;
  cin >>mapsize;
  Map *map = new Map(mapsize);

  system("clear");

  cout << "Quantos serao os numero de pontos:"<<endl;
  int number_points;
  cin >> number_points;

  system("clear");

  cout << "Prefere gerar pontos aleatorios (1)\n ou introduzi-los manualmente (2)\n";
  int inpt;
  cin >> inpt;

  system("clear");

  if(inpt==1){
    for(int i=0; i<number_points; ++i){
      int r1=rand()%(mapsize+1);//numero 0 -m
      int r2=rand()%(mapsize+1);

      int xsign = rand()%2;//sinal
      int ysign = rand()%2;

      if(xsign) r1*= -1;//atribuir sinal
      if(ysign) r2*= -1;

      Point *point = new Point(r1,r2);

      if(map->Contains(point)){
        i--;
      }
      else{ 
        map->Points.insert(map->Points.begin(),point);
      }
    } 
  }
  else{
    for(int i=0; i<number_points; ++i){
      int x1,y1; // 00 11 01 10
      cin >> x1>> y1;
      Point* p1 = new Point(x1,y1);
      map->Points.insert(map->Points.begin(),p1);
      system("clear");
    }
  }

  cout << "Aplicar uma permutacao (1)\n ou nearest-neigbour (2)\n";
  cin >> inpt;

  system("clear");
  
  if(inpt==1){
    random_vector(map);
  }
  else{
    nearest_Neighbour(map);
  }

  vector<vector<Point*>>* two_x = two_exchange(map->Path);

  cout << "Aplicar o Hill Climbing a partir do 2-exchange com as opcoes:\n";
  cout << "a) Menor perimetro"<<endl;
  cout << "b) Primeiro candidato"<<endl;
  cout << "c) Menos conflitos"<<endl;
  cout << "d) candidato aleatorio"<<endl;
  char a;
  cin >> a;
  system("clear");
  hill_climbing(a,two_x);
}