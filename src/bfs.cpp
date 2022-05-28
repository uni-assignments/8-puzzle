#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/bfs.hpp"

void BFS::search(State initial_state){
    queue<State> open_list; open_list.push(initial_state);
    this.mark_as_visited(initial_state.get_key());
    
    while(!open_list.empty()){
        State current = open_list.front(); open_list.pop();
        mark_as_visited(current.get_key());
        if(current.check_if_state_is_final()){
            return ;
        }

        for(auto move: current.get_possible_moves()){ 
            State to_be_explored = current.make_move(move);
            if(!this.state_was_visited(to_be_explored.get_key())){
                open_list.push_back(to_be_explored);
                this->parent[current.get_key()] = to_be_explored.get_key();
            }
        }
    }
}

stack<string> BFS::retrive_path(State initial_state){
    
    State parent ("123456780");
    string initial_key (initial_state.get_key());
    
    stack<string> path;

    while (parent.compare(initial_key)){
        path.push_back(parent);
        parent = this->parents[parent];
    }

    return path
}

void BFS::mark_as_visited(string state_key){
    this->visited[state_key] = true;
}

bool BFS::state_was_visited(string state_key){
    return this->visited[state_key];
}