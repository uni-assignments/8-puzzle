#include <iostream>
#include <string>
#include "../libs/state.hpp"

using namespace std;

State::State(vector<int> positions){
    this->positions = positions;

    for (int i = 0; i < 9; i++) if(positions[i] == 0) {
        this->empty_position = i;
        break;
    }

    if(this->empty_position > 2)                // 0, 1 and 2 cant go UP
        this->possible_moves.push_back(UP);   
    if((this->empty_position + 1) % 3 != 0)     // 2, 5 and 8 cant go RIGHT
        this->possible_moves.push_back(RIGHT);
    if(this->empty_position < 6)                // 6, 7 and 8 cant go DOWN
        this->possible_moves.push_back(DOWN);
    if(this->empty_position % 3 != 0)           // 0, 3 and 6 cant go LEFT
        this->possible_moves.push_back(LEFT);
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


int State::get_empty_position(){
    return this->empty_position;
}

vector<int> State::get_possible_moves(){
    return this->possible_moves;
}

string State::get_key(){
    string key;

    for(auto pos : this->positions){
        key.append(to_string(pos));
    }

    return key;
}

vector<int> State::generate_new_position(int next, int current){
    vector<int> config = this->positions;
    int aux = config[next];
    
    config[next] = 0;    config[current] = aux;
    return config;
}

State State::make_move(int move){
    int next, current = this->get_empty_position();
    
    switch (move){
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

bool State::check_if_state_is_final(){
    for(int i = 0; i < 8; i++){
        if(this->positions[i] != i + 1){
            return false;
        }
    }

    return true;
}