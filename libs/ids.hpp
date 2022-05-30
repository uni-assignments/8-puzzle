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
        bool state_is_white(string key);
        bool state_is_gray(string key);
        bool state_is_black(string key);
        void mark_as_white(string key);
        void mark_as_gray(string key);
        void mark_as_black(string key);
        bool dfs(State s, int limit);
        void search(State init_state);
};

#endif
