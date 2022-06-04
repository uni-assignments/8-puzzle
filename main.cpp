#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>

#include "./libs/state.hpp"
#include "./libs/bfs.hpp"
#include "./libs/ucs.hpp"
#include "./libs/ids.hpp"
#include "./libs/a_star.hpp"
#include "./libs/greedy.hpp"
#include "./libs/hill_climbing.hpp"

using namespace std;


void save_elapsed_time(char algorithm, int elapsed_time, int expanded_states){
    stringstream filename;
    filename << "./times/" <<  algorithm << ".csv";
    ofstream file(filename.str(), ios_base::app);
    file << elapsed_time << "," << expanded_states << endl;
    file.close();
}

void load_algorithm(char &algorithm, vector<int> &positions, bool &print_flag, bool &record_flag){

    State initial_state = State(positions);
    stack<string> path;
    Algorithm *alg;

    if(initial_state.is_goal()){
        cout << 0 << endl;
        return ;
    }  

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

    auto begin = chrono::steady_clock::now();
    alg->search(initial_state);
    path = alg->retrive_path(initial_state);
    auto end = chrono::steady_clock::now();
    
    int elapsed_time = chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    int expanded_states = alg->get_expanded_states();

    if(record_flag)
        save_elapsed_time(algorithm, elapsed_time, expanded_states);
    
    cout << path.size() - 1 << endl;
    if(print_flag)
        alg->print_path(path);
    
    delete(alg);
}

int main(int argc, char const *argv[]) {
    
    char algorithm = (char) *argv[1];

    vector<int> positions; 
    for(int i = 2; i < 11; i++)
        positions.push_back(atoi(argv[i]));

    bool print_flag = false, record_flag = false;
    string str_flag;

    if(argc > 11){
        str_flag = argv[11];
        if(str_flag.compare("PRINT") == 0) //Se o ultimo parametro passado for print
            print_flag = true;    
    }
    if(argc > 12){
        str_flag = argv[12]; 
        if(str_flag.compare("RECORD") == 0) //Se o ultimo parametro passado for record
            record_flag = true; 
    }

    load_algorithm(algorithm, positions, print_flag, record_flag);

    return 0;
}
