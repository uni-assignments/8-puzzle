#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/a_star.hpp"



void A_Star::search(State init_state){
    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> open_list; //Define heap, <dist, state>
    distance[init_state.get_key()] = 0;  
    int cost = distance[init_state.get_key()] + init_state.amount_of_wrong_pieces();                 // calculate cost (dist(x) + heuristic(x))
    open_list.emplace(cost, init_state);                                                     //Emplace node in heap 
    mark_as_found(init_state.get_key());                                                     //Mark node as found    
    
    while(not open_list.empty()){
        auto [cur_cost, cur_state] = open_list.top(); open_list.pop();                       //Pop smallest distance                                                
        
                                                            
        if (cur_cost > cur_state.amount_of_wrong_pieces() + distance[cur_state.get_key()])         //if path is worse then previous, skip
            continue;

        //loops through possible moves from current node
        for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
            parents[next_state.get_key()] = cur_state.get_key();                              // saves the parent of the node
            mark_as_found(next_state.get_key());                                              // mark the node as found
            expanded_states++;
            if(next_state.is_goal())                                                              //if node is goal, search can end
                return ;
            distance[next_state.get_key()] = distance[cur_state.get_key()] + 1;               // compute new distance
            cost = distance[next_state.get_key()] + next_state.amount_of_wrong_pieces();             // calculate cost (dist(x) + heuristic(x))
            open_list.emplace(cost, next_state);                                              // add  node in frontier
        }
    }
}