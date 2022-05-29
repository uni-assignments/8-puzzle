#include <iostream>
#include <vector>
#include <string>

#include "./libs/state.hpp"
#include "./libs/bfs.hpp"
#include "./libs/ucs.hpp"

using namespace std;

/*
void simple_tests(State initial_state){
    cout << "empty: " << initial_state.get_empty_position();
    
    initial_state.print_state();
    for (auto move : initial_state.get_possible_moves())
        cout << "podemos Mover: " << move << ", ";

    State new_state = initial_state.make_move(1);
    new_state.print_state();

    cout << initial_state.get_key() << endl;

    cout << initial_state.check_if_state_is_final() << endl;
}
*/

void load_algorithm(char &algorithm, vector<int> &positions, bool &flag){

    State initial_state = State(positions);
    stack<string> path;
    Algorithm *alg;

    switch(algorithm) {
        case 'B':
            alg = new BFS();
            break;
        case 'I':
            alg = new UCS();
            break;
    }

    alg->search(initial_state);
    path = alg->retrive_path(initial_state);
    cout << path.size() - 1 << endl;
    if(flag)
        alg->print_path(path);
    
    delete(alg);
}

int main(int argc, char const *argv[]) {
    
    char algorithm = (char) *argv[1];

    vector<int> positions; 
    for(int i = 2; i < 11; i++)
        positions.push_back(atoi(argv[i]));

    bool flag;
    string str_flag = argv[argc - 1]; flag = false;
    if(str_flag.compare("PRINT") == 0) //Se o ultimo parametro passado for print
        flag = true;    

    load_algorithm(algorithm, positions, flag);

    return 0;
}
