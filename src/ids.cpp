#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

#include "../libs/state.hpp"
#include "../libs/ids.hpp"

// bool IDS::dfs(State cur_state, int limit){
//     mark_as_found(cur_state.get_key());                                 //Initial node is marked as found
    
//     if(cur_state.is_goal()) return true;
//     if(distance[cur_state.get_key()] > limit) return false;

//     for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
//         parents[next_state.get_key()] = cur_state.get_key();                        // --> saves the parent of the node
//         distance[next_state.get_key()] = distance[cur_state.get_key()] + 1;         // --> calculate distance
        
//         if (dfs(next_state, limit)) 
//             return true;
//     }   
//     return false;
// }

bool IDS::dfs(State init_state, int limit){

    stack<State> open_list; open_list.push(init_state);
    mark_as_found(init_state.get_key()); distance[init_state.get_key()] = 0;   //Mark initial node with distance 0 
    
    while(not open_list.empty()){
        State cur_state = open_list.top(); open_list.pop();                               //Pop smallest distance                                                
        if (distance[cur_state.get_key()] > limit) continue;                              //if path breaks limit, skip
    
        //loops through possible moves from current node
        for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
            distance[next_state.get_key()] = distance[cur_state.get_key()] + 1;               // --> calculate distance
            mark_as_found(next_state.get_key());                                              // --> mark the node as found
            parents[next_state.get_key()] = cur_state.get_key();                              // --> saves the parent of the node
            if(next_state.is_goal()) return true;                                              //if node is goal, search can end
            open_list.push(next_state);                                                       // --> add  node in frontier
        }
    }
    return false;
}


void IDS::search(State init_state){
    for(int i = 1;i<30; i++){
        found.clear();
        distance.clear();
        distance[init_state.get_key()] = 0;                                  //Mark initial node with distance 0

        if(dfs(init_state, i)) break;
    }
}