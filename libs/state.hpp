#ifndef STATE_HEADER

#include<vector>

using namespace std;

enum Directions{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

class State {

    private: 
        vector<int> positions;
        int empty_position;
        vector<int> possible_moves;

    public:
        State(vector<int> positions);
        
        int get_empty_position();
        vector<int> get_possible_moves();
        vector<int> generate_new_position(int next, int current);
        State make_move(int move);
        string get_key();
        void print_state();
        bool check_if_state_is_final();
}; 

#endif
