#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/bfs.hpp"

void BFS::search(State init_state){
    queue<State> open_list; open_list.push(init_state);                  //Queue with nodes from frontier
    mark_as_found(init_state.get_key());                                 //Initial node is marked as found
    
    while(not open_list.empty()){                                           //Loop while theres nodes to be explored 
        State cur_state = open_list.front(); open_list.pop();                 //Fetch next node in frontier     

        //loops through possible moves from current node
        for(State next_state: cur_state.get_possible_actions()) if(not state_was_found(next_state.get_key())) {    
            parents[next_state.get_key()] = cur_state.get_key();              // --> saves the parent of the node
            mark_as_found(next_state.get_key());                               // --> mark the node as found
            expanded_states++;
            if(next_state.is_goal()) return ;                                             //if node is goal, search can end

            open_list.push(next_state);                                     // --> add  node in frontier
            
        } 
    }
}