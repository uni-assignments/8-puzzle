#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

#include "../libs/state.hpp"
#include "../libs/ids.hpp"


bool IDS::state_is_white(string key){
    return found[key] == 0;
}

bool IDS::state_is_black(string key){
    return found[key] == 1;
}

void IDS::mark_as_white(string key){
    found[key] = 0;
}

void IDS::mark_as_black(string key){
    found[key] = 1;
}


bool IDS::dfs(State cur_state, int limit){

    if(cur_state.is_goal()) return true;                                  // found solution, can leave
    if(limit == 0) return false;                                          // reached limit 

    mark_as_black(cur_state.get_key());
    for(State next_state: cur_state.get_possible_actions()) {
        if(not state_is_black(next_state.get_key())){    
            parents[next_state.get_key()] = cur_state.get_key();          // --> saves the parent of the node
            if (dfs(next_state, limit - 1))               
                return true;
        }   
    }

    mark_as_white(cur_state.get_key());
    return false;
}


void IDS::search(State init_state){
    for(int i = 1;; i++){
        parents.clear();
        found.clear();
        if(dfs(init_state, i)) break;
    }
}