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
            Vec* t = new Vec(next_Point,current_Point);
            Line* l = new Line(v,t);
            m->Lines.push_back(l);
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
                   
double cross_Product(int x1,int y1,int x2,int y2){
    return (x1*y2)-(x2*y1);    
}

bool on_segment(Point* p1, Point* p2, Point* p3){ //check if p3 is on p1p2 line
   
    if((min(p1->x,p2->x) <= p3->x) && 
       (p3->x <= max(p1->x,p2->x)) && 
       (min(p1->y,p2->y) <= p3->y) && 
       (p3->y <= max(p1->y,p2->y))) return true;
        
        else return false;
}
                    
/*bool legal_intersect(Point* p1, Point* p2, Point* p3, Point* p4){
    if((p1 != p4) 
    && (p2 != p3)) return true;/*
    p1 - p3
    p2 - p4
    && (v1->start  != v2->start)
    && (v1->finish != v1->finish)) return true;
    else return false;
}
*/

bool vectors_Intersect(Point* p1i, Point* p1f, Point* p2i, Point* p2f){
                            //reta P1i->P1f & P1i->P2i

                            //p1f-p1i // p2i-p1i
    double d1 = 
    cross_Product((p1f->x-p1i->x),(p1f->y-p1i->y),
                  (p2i->x-p1i->x),(p2i->y-p1i->y));

                            //reta P1i->P1f & P1i->P2f
    double d2 = cross_Product((p1f->x-p1i->x),(p1f->y-p1i->y),
                              (p2f->x-p1i->x),(p2f->y-p1i->y));
    
                            //reta P2i->P2f & P2i->P1i
    double d3 = cross_Product((p2f->x-p2i->x),(p2f->y-p2i->y),
                              (p1i->x-p2i->x),(p1i->x-p2i->y));

                            //reta P2i->P2f & P2i->P1f
    double d4 = cross_Product((p2f->x-p2i->x),(p2f->y-p2i->y),
                              (p1f->x-p2i->x),(p1f->x-p2i->y));
    
    if(((d1>0 && d2<0) || (d1<0 && d2>0)) &&
    ((d3>0 && d4<0) || (d3<0 && d4>0)))
    return true;

    else if((d1==0) && 
        (on_segment(p1i,p1f,p2i)))
        return true;
    else if((d2==0) && 
        (on_segment(p1i,p1f,p2f)))
        return true;
    else if((d3==0) && 
        (on_segment(p2i,p2f,p1i)))
        return true;
    else if((d4==0) && 
        (on_segment(p2i,p2f,p1f)))
        return true;

    return false;
}

vector<vector<Point*>>* two_exchange(vector<Point*> p){
    vector<vector<Point*>> *Solution;

    for(int i = 1; i<p.size(); i++){
        for(int j = 1; j<=p.size(); j++){
            int a,b;
            if(j==p.size()){
                a=0;
                b=p.size()-1;
            }
            else{
                a=j;
                b=j-1;
            }
            if(b!=(i-1) && b!=i && a!=i && a!=i-1){
                //considerar interesefa entre i <-> i-1 e j <-> j-1 
                if(vectors_Intersect(p[i-1],p[i],p[a],p[b])) {
                    //criar new vector<point>
                    //altera duas 
                    // pushback new

                    //0->i cp
                    //i swap a
                    //reverse entre i--a
                    //b->size-1 cp
                    vector<Point*> tmp=p;
                    if(a<i){
                        reverse(tmp.begin()+a,tmp.begin()+i);
                        Point *t = tmp[i];
                        tmp[i]=tmp[a];
                        tmp[a]=t;
                    }
                    else{
                        reverse(tmp.begin()+i,tmp.begin()+a);
                        Point *t = tmp[i];
                        tmp[i]=tmp[a];
                        tmp[a]=t;
                    }
                    for(auto const& i : tmp){
                        i->Point_Print();
                    }
                    Solution->push_back(tmp);                    
                }  
            }
        }
    }

    return Solution;
}
/* 
    //nearest_Neighbour(m);
    //print_Path(m);

    cout<<"_------------------------------------------_"<<endl;
   
    // cout << "size:" << m->Links.size()<< endl;
    // for(int i =0; i<m->Links.size();++i) m->Links[i]->Vec_Print();
    
    for(int i =0; i<m->Lines.size();++i){//vec i
        for(int j =0; j<m->Lines.size();++j){//vec j
            if(i==j){
                continue;
            }
            //m->Lines[i]->v1->Vec_Print();
            //m->Lines[j]->v1->Vec_Print();
            if(legal_intersect(m->Lines[i]->v1,m->Lines[j]->v1)){
                if(vectors_Intersect(m->Lines[i]->v1,m->Lines[j]->v2)){

                    cout << "intersecao na lina" << endl;
                    m->Links[i]->Vec_Print();
                    m->Links[j]->Vec_Print();

                    cout << "tentar corrigir para" << endl;
                    //new vec v1(i->start,j->start)
                    Vec *v1 = new Vec(m->Lines[i]->v1->start,m->Lines[j]->v1->start);
                    //new vec v2(i->finish,j->finish)
                    Vec *v2 = new Vec(m->Lines[j]->v1->start,m->Lines[i]->v1->start);

                    Vec *v3 = new Vec(m->Lines[i]->v1->finish,m->Lines[j]->v1->finish);
                    //new vec v2(i->finish,j->finish)
                    Vec *v4 = new Vec(m->Lines[j]->v1->finish,m->Lines[i]->v1->finish);
                    
                    Line *l1 = new Line(v1,v2);
                    Line *l2 = new Line(v3,v4);

                    
                    v1->Vec_Print();
                    v2->Vec_Print();
                    v3->Vec_Print();
                    v4->Vec_Print();

                    if(i<j){
                        m->Lines.erase(m->Lines.begin()+i);
                        m->Lines.erase(m->Lines.begin()+j-1);
                    }
                    else{
                        m->Lines.erase(m->Lines.begin()+i);
                        m->Lines.erase(m->Lines.begin()+j);
                    }
 

                    m->Lines.push_back(l1);
                    m->Lines.push_back(l2);
                    
                }
            }
        }
    } 

    for(auto const& i : m->Lines){
        if(i->v1->start->l1_visited)
            i->v1->start->l2=i;
        else
            i->v1->start->l1=i;
        
        if(i->v1->finish->l1_visited)
            i->v1->finish->l2=i;
        else
            i->v1->finish->l1=i;
    }
    
    while (!m->Openlist.empty()){
     m->Openlist.pop_back();
    }
    
    while (!m->Path.empty()){
     m->Path.pop_back();
    }
    
    for(auto const& i : m->Points){
        i->visited = false;
    }
    
    int r =rand()%(m->Points.size()-1);
    
    Point *inicial_Point = m->Points[r];

    m->Openlist.push_back(inicial_Point);
    m->Path.push_back(inicial_Point);

    

    bool goalFound=false;
    Point *prev_Point=m->Openlist[0];
    Point *current_Point=m->Openlist[0];

    while(!goalFound){
        prev_Point=current_Point;
        current_Point = m->Openlist[0];
        //current_Point->Print();
        m->Openlist.erase(m->Openlist.begin());
        
        current_Point->visited=true;

        Point *next_Point;
        
        
        if(current_Point->l1->v1->finish !=current_Point 
        || current_Point->l1->v1->finish !=prev_Point){
            next_Point=current_Point->l1->v1->finish;
        }
        else if(current_Point->l1->v2->finish !=current_Point 
        || current_Point->l1->v2->finish !=prev_Point){
            next_Point=current_Point->l1->v2->finish;
        }
        else if(current_Point->l2->v1->finish !=current_Point 
        || current_Point->l2->v1->finish !=prev_Point){
            next_Point=current_Point->l2->v1->finish;
        }
        else if(current_Point->l2->v2->finish !=current_Point 
        || current_Point->l2->v2->finish !=prev_Point){
            next_Point=current_Point->l2->v2->finish;
        }     
        

        
        if(next_Point->visited){
            goalFound=true;
            continue;
        }
        m->Path.push_back(next_Point);
        m->Openlist.push_back(next_Point);
    }
    

    m->Path.push_back(inicial_Point);
    
    for(auto const& i : m->Lines){
        cout<<"v1:\n";
        i->v1->Vec_Print();
        cout<<"v2:\n";
        i->v2->Vec_Print();
    }

}
bool check_visited( vector<Point*> Points){
    for(auto const& i : Points){
        if(!i->visited){
            return false;
        }
    }
    return true;
}
/*
void two_exchange(Map *m){
    nearest_Neighbour(m);
    //links->caminho mais perto direcionado

    m->Print_Vecs();

    for(auto const& i : m->Points){
        i->visited = false;
    }
    /*
    abc -> links
    cba -> nlinks
    */
    /*vector<Vec*> counter_Links;
    for(auto const& i : m->Links){
        Vec *v1 = new Vec(i->finish,i->start);
        counter_Links.insert(counter_Links.begin(),v1);
    }
*//*
    //while houver Points por visitar && intersecoes 
    bool goalFound=false;

}
*/