#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/greedy.hpp"


void Greedy::search(State init_state){
    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> open_list; //Define heap, <dist, state>
    open_list.emplace(init_state.sum_of_distance(), init_state);                           //Emplace node in heap measured by heuristic
    mark_as_found(init_state.get_key());                                                     //Mark node as found    
    
    while(not open_list.empty()){
        auto [cur_h, cur_state] = open_list.top(); open_list.pop();                       //Pop smallest distance                                                
        
        if(cur_state.is_goal()) return ;                                                     //if node is goal, search can end
    
        //loops through possible moves from current node
        for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
            open_list.emplace(next_state.sum_of_distance(), next_state);                    // --> add  node in frontier
            mark_as_found(next_state.get_key());                                              // --> mark the node as found
            parents[next_state.get_key()] = cur_state.get_key();                              // --> saves the parent of the node
        }
    }
}