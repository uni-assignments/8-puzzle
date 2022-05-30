#ifndef IDS_HEADER
#define IDS_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class IDS : public Algorithm{
    private:
        map<string, int> distance;
    
    public:
        bool dfs(State s, int limit);
        void search(State init_state);
};

#endif
