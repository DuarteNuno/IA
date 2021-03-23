#include "search.h"

void random_vector(Map *m){
    random_shuffle(m->Points.begin(), m->Points.end());
    m->Print_Points();
}

void order(Map *m){ 
    m->Print_Points();
}

void print_Path(Map *m){ 
    for(auto const& i : m->Path){
        i->Point_Print();
    }
}

void nearest_Neighbour(Map *m){

    int r =rand()%(m->Points.size()-1);
    //cout << "r: " << r << endl;
    
    Point *inicial_Point = m->Points[r];
    Point *final_point;
    
    m->Openlist.push_back(inicial_Point);
    m->Path.push_back(inicial_Point);

    bool goalFound=false;
    
    while(!goalFound){
        Point *current_Point = m->Openlist[0];
        //current_Point->Print();
        m->Openlist.erase(m->Openlist.begin());
        
        current_Point->visited=true;

        double dist_min=sqrt(pow(m->MaxN*2,2)+pow(m->MaxN*2,2));//diagonal
        Point *next_Point;
        next_Point=current_Point;
        
        for(auto const& i :m->Points){
            
            if(!i->visited){

                int x = i->x - current_Point->x; //calculating number to square in next step
                int y = i->y - current_Point->y;
                double dist;

                dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
                dist = sqrt(dist);

                if(dist<=dist_min){
                    dist_min=dist;
                    next_Point=i;
                }
            }
        }

        if(!next_Point->visited){
            m->Openlist.push_back(next_Point);
            m->Path.push_back(next_Point);
            Vec* v = new Vec(current_Point,next_Point);
            m->Links.push_back(v);
        }

        else{
            //next_Point->Print();
            goalFound=true;
            final_point=next_Point;
        }

    }
    m->Path.push_back(inicial_Point);
    Vec* vfinal = new Vec(final_point,inicial_Point);
    m->Links.push_back(vfinal);

}

double cross_Product(Vec* v1, Vec* v2){
    return (v1->x*v2->y)-(v2->x*v1->y);    
}

bool on_segment(Point* p1, Point* p2, Point* p3){ //check if p3 is on p1p2 line
   
    if((min(p1->x,p2->x) <= p3->x) && 
       (p3->x <= max(p1->x,p2->x)) && 
       (min(p1->y,p2->y) <= p3->y) && 
       (p3->y <= max(p1->y,p2->y))) return true;
        
        else return false;
}

bool vectors_Intersect(Vec* v1, Vec* v2){

    Vec *tmp1 = new Vec(v1->start,v2->start);
                            //reta P1i->P1f & P1i->P2i
    double d1 = cross_Product(v1,tmp1);
                        
    Vec *tmp2 = new Vec(v1->start,v2->finish);
                            //reta P1i->P1f & P1i->P2f
    double d2 = cross_Product(v1,tmp2);
    
    Vec *tmp3 = new Vec(v2->start,v1->start);
                            //reta P2i->P2f & P2i->P1i
    double d3 = cross_Product(v2,tmp3);

    Vec *tmp4 = new Vec(v2->start,v1->finish);
                            //reta P2i->P2f & P2i->P1f
    double d4 = cross_Product(v2,tmp4);
    
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&
      ((d3>0 && d4<0) || (d3<0 && d4>0)))
      return true;

    else if((d1==0) && 
           (on_segment(v1->start,v1->finish,v2->start)))
           return true;
    else if((d2==0) && 
           (on_segment(v1->start,v1->finish,v2->finish)))
           return true;
    else if((d3==0) && 
           (on_segment(v2->start,v2->finish,v1->start)))
           return true;
    else if((d4==0) && 
           (on_segment(v2->start,v2->finish,v1->finish)))
           return true;

    return false;
}


bool legal_intersect(Vec* v1,Vec* v2){
    if((v1->start  != v2->finish)
    && (v1->finish != v2->finish)
    && (v1->start  != v2->start)
    && (v1->finish != v2->start)) return true;
    else return false;
}

void two_exchange(Map *m){
    
    nearest_Neighbour(m);
   // print_Path(m);
   //cout<<"2x"<<endl;
   // cout << "size:" << m->Links.size()<< endl;
   // for(int i =0; i<m->Links.size();++i) m->Links[i]->Vec_Print();
    
      for(int i =0; i<m->Links.size();++i){//vec i
        for(int j =0; j<m->Links.size();++j){//vec j
            if(legal_intersect(m->Links[i],m->Links[j])){
                if(vectors_Intersect(m->Links[i],m->Links[j])){
                   cout << "detetei treta" << endl;
                    m->Links[i]->Vec_Print();
                    m->Links[j]->Vec_Print();

                    cout << "sou burro" << endl;
                    //new vec v1(i->start,j->start)
                    Vec *v1 = new Vec(m->Links[i]->start,m->Links[j]->start);
                    //new vec v2(i->finish,j->finish)
                    Vec *v2 = new Vec(m->Links[i]->finish,m->Links[j]->finish);
                     
                     v1->Vec_Print();
                     v2->Vec_Print();

                    m->Links.push_back(v1);
                    m->Links.push_back(v2);
                    m->Links.erase(m->Links.begin()+i);
                    m->Links.erase(m->Links.begin()+j);
                    
                   //cout<< "int"<<endl;
                }
            }
        }
    } 

   for(int i =0; i<m->Links.size();++i) m->Links[i]->Vec_Print();
   
}