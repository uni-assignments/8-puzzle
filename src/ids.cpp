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

bool IDS::state_is_gray(string key){
    return found[key] == 1;
}

bool IDS::state_is_black(string key){
    return found[key] == 2;
}

void IDS::mark_as_white(string key){
    found[key] = 0;
}

void IDS::mark_as_gray(string key){
    found[key] = 1;
}

void IDS::mark_as_black(string key){
    found[key] = 2;
}

bool IDS::dfs(State cur_state, int limit){
    if (state_is_gray(cur_state.get_key())) return false;

    mark_as_gray(cur_state.get_key()); //node was visited once
    if(cur_state.is_goal()) return true; //found solution, can leave
    if(distance[cur_state.get_key()] > limit) return false; //

    for(State next_state: cur_state.get_possible_actions()){    
        parents[next_state.get_key()] = cur_state.get_key();                        // --> saves the parent of the node
        distance[next_state.get_key()] = distance[cur_state.get_key()] + 1;         // --> calculate distance
        
        if (state_is_white(next_state.get_key()) and dfs(next_state, limit)) 
            return true;
    }   

    mark_as_black(cur_state.get_key());
    return false;
}

// bool IDS::dfs(State init_state, int limit){

//     stack<State> open_list; open_list.push(init_state);
//     distance[init_state.get_key()] = 0;   //Mark initial node with distance 0 
    
//     while(not open_list.empty()){
//         State cur_state = open_list.top();                                                                               
//         if (distance[cur_state.get_key()] > limit) continue;                                //if path breaks limit, skip
//         if (cur_state.is_goal())  return true;                                              //if node is goal, search can ends
         
//         if(not state_is_gray(cur_state.get_key())){
//             mark_as_gray(cur_state.get_key());
//             //loops through possible moves from current node
//             for(State next_state: cur_state.get_possible_actions()) {    
//                 if(state_is_white(next_state.get_key())){                                                             
//                     open_list.push(next_state);                                                       // --> add  node in frontier
//                     parents[next_state.get_key()] = cur_state.get_key();                              // --> saves the parent of the node
//                     distance[next_state.get_key()] = distance[cur_state.get_key()] + 1;               // --> calculate distance
//                 } 
//                 else if (state_is_gray(next_state.get_key()))
//                     return false;
                
//             }
//         } else if(state_is_gray(cur_state.get_key())){
//             open_list.pop();
//             mark_as_black(cur_state.get_key());
//         }
//     }
//     return false;
// }


void IDS::search(State init_state){
    for(int i = 1;; i++){
        // cout << "level " << i << endl;
        found.clear();
        distance.clear();
        distance[init_state.get_key()] = 0;                                  //Mark initial node with distance 0

        if(dfs(init_state, i)) break;
    }
}