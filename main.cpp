#include <iostream>
#include <vector>
#include <string>

#include "./libs/state.hpp"
#include "./libs/bfs.hpp"
#include "./libs/ucs.hpp"
#include "./libs/ids.hpp"
#include "./libs/a_star.hpp"
#include "./libs/greedy.hpp"
#include "./libs/hill_climbing.hpp"

using namespace std;

void load_algorithm(char &algorithm, vector<int> &positions, bool &flag){

    State initial_state = State(positions);
    stack<string> path;
    Algorithm *alg;

    switch(algorithm) {
        case 'B':
            alg = new BFS();
            break;
        case 'I':
            alg = new IDS();
            break;
        case 'U':
            alg = new UCS();
            break;
        case 'A':
            alg = new A_Star();
            break;
        case 'G':
            alg = new Greedy();
            break;
        case 'H':
            alg = new HillClimbing();
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
