#ifndef STATE_HEADER
#define STATE_HEADER

#include<vector>
#include<string>

using namespace std;

enum Directions{
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

class State {

    private: 
        string key;
        vector<int> positions;
        int empty_position;
        vector<int> possible_actions;

    public:
        State(vector<int> positions);
        static void print_state(string state_key);

        bool operator<(State const &s) const;
        
        int get_empty_position();
        vector<State> get_possible_actions();
        vector<int> generate_new_position(int next, int current);
        State make_action(int action);
        string get_key();
        bool is_goal();

        int amount_of_wrong_pieces();
        int sum_of_distance();
}; 

#endif
