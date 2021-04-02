#include "search.h"

void nearest_Neighbour(Map *m){

    int r =rand()%(m->Points.size()-1);
    
    Point *inicial_Point = m->Points[r];
    Point *final_point;
    
    m->Openlist.push_back(inicial_Point);
    m->Path.push_back(inicial_Point);

    bool goalFound=false;
    
    while(!goalFound){
        Point *current_Point = m->Openlist[0];
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

                dist = pow(x, 2) + pow(y, 2);//calculating Euclidean distance
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
            goalFound=true;
            final_point=next_Point;
        }

    }
    m->Path.push_back(inicial_Point);

}

vector<Point*> hill_climbing(char opt, vector<Point*> inicial ){

    vector<Point*> best = inicial;

    vector<vector<Point*>>* candidates = two_exchange(best);

    vector<Point*> neighbour = choose_opt(opt, candidates);

    while((neighbour.size()>0)){

        double best_per=perimeters(best);
        double neighbour_per=perimeters(neighbour);

        if(neighbour_per<best_per){
            best=neighbour;
            candidates=two_exchange(best);
            neighbour=choose_opt(opt,candidates);
        }
        else{
            break;
        }
    }
        
    return best;
}

vector<Point*> simulated_annealing(vector<Point*> inicial){   
    vector<Point*> best = inicial;

    vector<Point*> neighbour = choose_opt('c',two_exchange(inicial));
    vector<vector<Point*>>* candidates = two_exchange(best);

    int temp = n_Intersections(inicial);

    while((neighbour.size()>0 && temp>0)){

        double best_per=perimeters(best);
        double neighbour_per=perimeters(neighbour);

        if(accept(best_per,neighbour_per,temp)){
            best=neighbour;
            candidates=two_exchange(best);
            neighbour=choose_opt('c',candidates);
            temp = n_Intersections(best);
        }
        else{
            temp--;
        }
    }
    return best;
}