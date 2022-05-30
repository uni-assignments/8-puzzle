#ifndef GREEDY_HEADER
#define GREEDY_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class Greedy : public Algorithm{
    public:
        void search(State init_state);
};

#endif
