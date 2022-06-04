#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/hill_climbing.hpp"


void HillClimbing::search(State init_state){
    int lim = 25;
    State current = init_state;
    while(lim--){
        State neighbor = State();
        int best_value = 0;
        for(State next_state: current.get_possible_actions()){
            if(next_state.value() > best_value){
                best_value = next_state.value();
                neighbor = next_state;
            }
            expanded_states++;
        }    
        if(neighbor.value() < current.value())
            return ;

        parents[neighbor.get_key()] = current.get_key();
        current = neighbor;
    }
}