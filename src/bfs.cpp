#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/bfs.hpp"

void BFS::search(State initial_state){
    queue<State> open_list; open_list.push(initial_state);
    this->mark_as_visited(initial_state.get_key());
    
    while(!open_list.empty()){
        State current = open_list.front(); open_list.pop();
        this->mark_as_visited(current.get_key());
        if(current.check_if_state_is_final()){
            return ;
        }

        for(auto move: current.get_possible_moves()){ 
            State to_be_explored = current.make_move(move);
            if(!this->state_was_visited(to_be_explored.get_key())){
                open_list.push(to_be_explored);
                this->parents[to_be_explored.get_key()] = current.get_key();
            }
        }
    }
}