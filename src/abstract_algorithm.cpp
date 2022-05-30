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
    if(parents.count(parent) > 0) {
        while (parent.compare(initial_key)){
            path.push(parent);
            parent = this->parents[parent];
        }
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

void Algorithm::mark_as_found(string state_key){
    this->found[state_key]++;
}

bool Algorithm::state_was_found(string state_key){
    return this->found.count(state_key) > 0;
}