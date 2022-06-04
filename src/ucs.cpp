#include <iostream>
#include <fstream>

#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/ucs.hpp"

using namespace std;

void UCS::search(State init_state){

    priority_queue<pair<int, State>, vector<pair<int, State>>, greater<pair<int, State>>> open_list; //Define heap, <dist, state>
    distance[init_state.get_key()] = 0;                                                      //Mark initial node with distance 0
    open_list.emplace(distance[init_state.get_key()], init_state);                           //Emplace node in heap
    mark_as_found(init_state.get_key());                                                     //Mark node as found    
    
    while(not open_list.empty()){
        auto [cur_dist, cur_state] = open_list.top(); open_list.pop();                       //Pop smallest distance                                                
        
        if(cur_state.is_goal()) return ;                                                     //if node is goal, search can end
        if (cur_dist > distance[cur_state.get_key()]) continue;                              //if path is worse then previous, skip
    
        //loops through possible moves from current node
        for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
            distance[next_state.get_key()] = cur_dist + 1;                                    // --> calculate distance
            open_list.emplace(distance[next_state.get_key()], next_state);                    // --> add  node in frontier
            mark_as_found(next_state.get_key());                                              // --> mark the node as found
            expanded_states++;
            parents[next_state.get_key()] = cur_state.get_key();                              // --> saves the parent of the node
        }
    }
}