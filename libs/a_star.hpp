#ifndef ASTAR_HEADER
#define ASTAR_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class A_Star : public Algorithm{
    private:
        map<string, int> distance;
    public:
        void search(State init_state);
};

#endif
