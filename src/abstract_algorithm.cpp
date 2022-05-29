#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/abstract_algorithm.hpp"

using namespace std;

void Algorithm::search(State initial_state){
    cout << "Selecione um algoritmo válido" << endl;
}

stack<string> Algorithm::retrive_path(State initial_state){
    
    string parent ("123456780");
    string initial_key (initial_state.get_key());
    
    stack<string> path;

    while (parent.compare(initial_key)){
        path.push(parent);
        parent = this->parents[parent];
    }

    path.push(initial_key);

    return path;
}

void Algorithm::print_path(stack<string> path){
    string current_state;
    
    while(!path.empty()){
        current_state = path.top(); path.pop();
        State::print_state(current_state);
    }
}

void Algorithm::mark_as_visited(string state_key){
    this->visited[state_key] = true;
}

bool Algorithm::state_was_visited(string state_key){
    return this->visited[state_key];
}