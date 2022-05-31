#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

#include "../libs/state.hpp"
#include "../libs/hill_climbing.hpp"


void HillClimbing::search(State init_state){
    int lim = 10;
    State current = init_state;
    while(lim--){
        State neighbor = State();
        int best_value = 0;
        cout << current.get_key() << endl;
        for(State next_state: init_state.get_possible_actions()){
            if(next_state.value() > best_value){
                best_value = next_state.value();
                neighbor = next_state;
            }
        }    
        cout << "n value: " << neighbor.value() << " c value: " << current.value() << endl;
        if(neighbor.value() < current.value())
            return ;

        parents[neighbor.get_key()] = current.get_key();
        current = neighbor;
    }
}