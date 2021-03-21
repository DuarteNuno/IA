#include "search.h"

void random_vector(Map *m){
    random_shuffle(m->Points.begin(), m->Points.end());
    m->PrintPoints();
}

void order(Map *m){ 
    m->PrintPoints();
}

void print_Path(Map *m){ 
    for(auto const& i : m->Path){
        i->Print();
    }
}

/*
void permutation(Map *m){
    perm(m->Points, m->Points.size()-1);
    
}

void perm(vector<Point*> list, int final){
    vector<Point*> target;
    vector<Point*> cp=list;
        
    for(int i = final;i>=0;i--){
        int r;
        if(i==0) r=0;
        else r=rand()%i;
        target.push_back(cp[r]);
        cp.erase(cp.begin()+r);
    }
    for(auto const& i : target){
        i->Print();
    }
}
*/

void nearest_Neighbour(Map *m){

    int r =rand()%(m->Points.size()-1);
    //cout << "r: " << r << endl;
    
    Point *inicial_Point = m->Points[r];
    
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
        }

        else{
            //next_Point->Print();
            goalFound=true;
        }
    }
}


double crossProduct(int x1, int y1, int x2, int y2){
    return (x1*y2)-(x2*y1);    
}

bool clockwise(Point* a, Point* b){
    if(crossProduct(a->x,a->y,b->x,b->y)>0) return true;
    else return false;
}