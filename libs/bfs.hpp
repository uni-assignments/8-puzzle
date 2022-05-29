#ifndef BFS_HEADER
#define BFS_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class BFS : public Algorithm{
    public:
        void search(State init_state);
};

#endif
