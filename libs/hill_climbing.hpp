#ifndef HILL_HEADER
#define HILL_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class HillClimbing : public Algorithm{
    public:
        void search(State init_state);
};

#endif
