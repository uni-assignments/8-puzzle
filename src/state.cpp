#include <iostream>
#include <cmath>
#include <string>

#include "../libs/state.hpp"

using namespace std;

State::State(vector<int> positions){
    this->positions = positions;

    for(auto pos : this->positions){
        this->key.append(to_string(pos));
    }

    for (int i = 0; i < 9; i++) if(positions[i] == 0) {
        this->empty_position = i;
        break;
    }

    if(this->empty_position > 2)                // 0, 1 and 2 cant go UP
        this->possible_actions.push_back(UP);   
    if((this->empty_position + 1) % 3 != 0)     // 2, 5 and 8 cant go RIGHT
        this->possible_actions.push_back(RIGHT);
    if(this->empty_position < 6)                // 6, 7 and 8 cant go DOWN
        this->possible_actions.push_back(DOWN);
    if(this->empty_position % 3 != 0)           // 0, 3 and 6 cant go LEFT
        this->possible_actions.push_back(LEFT);
}

void State::print_state(string state_key){
    cout << endl;
    for(int i = 0; i < 9; i++){
        if(state_key[i] == '0') cout << "  ";
        else  cout << state_key[i] << " "; 
        
        if((i + 1) % 3 == 0) 
            cout << endl;    
    }
}

bool State::operator<(State const &s) const {
    return s.key < this->key;
}

int State::get_empty_position(){
    return this->empty_position;
}

string State::get_key(){
    return this->key;
}

vector<int> State::generate_new_position(int next, int current){
    vector<int> config = this->positions;
    int aux = config[next];
    
    config[next] = 0;    config[current] = aux;
    return config;
}

State State::make_action(int action){
    int next, current = this->get_empty_position();
    
    switch (action){
        case UP:
            next = current - 3;
            break;
        case RIGHT:
            next = current + 1;
            break;
        case DOWN:
            next = current + 3;
            break;
        case LEFT:
            next = current - 1;
            break;
    }
    
    vector<int> config = this->generate_new_position(next, current);
    return State(config);
}

vector<State> State::get_possible_actions(){
    vector<State> next_states;
    for (auto action: this->possible_actions)
        next_states.push_back(this->make_action(action));
    
    return next_states;
}

bool State::is_goal(){
    for(int i = 0; i < 8; i++){
        if(this->positions[i] != i + 1){
            return false;
        }
    }

    return true;
}


// -------------------------------------------------------- Heuristics ----------------------------------------------------

int State::value(){
    int count = 0;
    for(int i = 0; i < 9; i++) if(this->positions[i] == i + 1){
        count++;
    }
    return count;
}

int State::amount_of_wrong_pieces(){
    int count = 0;
    for(unsigned i = 0; i < 9; i++) if(this->positions[i] != i+1) {
        count++;
    }
    return count;
}

int State::sum_of_distance(){
    int state_x, correct_x, state_y, correct_y, sum = 0;
    for(unsigned i = 0; i < 9; i++) {
        state_x = this->positions[i] % 3;
        correct_x = (i + 1) % 3;
        state_y = ceil(this->positions[i]/3);
        correct_y = ceil(this->positions[i]/3);

        sum += (abs(state_x - correct_x) + abs(state_y - correct_y));
    }

    return sum;
}