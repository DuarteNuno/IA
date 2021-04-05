#include "search.h"

/*
 *Autores: @Duarte Alves e @Manuel Sá
 *---------up201805437----up201805273--
 *
 * 
 *Agradecemos a colaboraçao das colegas @Patricia Vieira e @Catarina Teixeira
 *----------------------------------------up201805238--------up201805042-------
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
      cout << "x e y do ponto" << i+1 << endl;
      if(i>0) cout << "nota: nao inserir pontos já existentes\n";
      int x1,y1; // 00 11 01 10
      cin >> x1>> y1;
      Point* p1 = new Point(x1,y1);
       if(map->Contains(p1)){
        i--;
      }
      else map->Points.insert(map->Points.begin(),p1);
      system("clear");
    }
  }

  cout << "Aplicar uma permutacao (1)\nNearest-neigbour (2)\n";
  cin >> inpt;

  system("clear");
  
  if(inpt==1) random_vector(map);
  else nearest_Neighbour(map);
  cout << "Caminho obtido atraves do metodo selcionado:\n";
   for(auto const& i : map->Path){
          cout<<"("<< i->x << "," << i->y << ")";
      }
      cout << "\n\n";
  

  char searcher;
  cout << "Selicionar Método de pesquisa:"<<endl;
  cout << "Hill_Climbing (1)\n";
  cout << "Simulated Annealing (2)\n";
  if(number_points<200){
    cout << "Ant Colony (3) \n";
  }
  cin >> searcher;

  if(searcher=='1'){
    cout << "Aplicar o Hill Climbing a partir do 2-exchange com as opcoes:\n";
    cout << "a) Menor perimetro"<<endl;
    cout << "b) Primeiro candidato"<<endl;
    cout << "c) Menos conflitos"<<endl;
    cout << "d) candidato aleatorio"<<endl;
    char a;
    cin >> a;
    system("clear");
    vector<Point*> res = hill_climbing(a,map->Path);
    for(auto const& i : res){
          cout<<"("<< i->x << "," << i->y << ")";
      }
      cout << endl; 
  }
  else if(searcher=='2'){
    vector<Point*> res = simulated_annealing(map->Path);
    for(auto const& i : res){
      cout<<"("<< i->x << "," << i->y << ")";
    } 
     cout << endl; 
  }
  else{
    vector<Point*> res = ant_colony(map->Points);
   
    for(auto const& i : res){
      cout<<"("<< i->x << "," << i->y << ")";
    } 
     cout << endl;
  }
}