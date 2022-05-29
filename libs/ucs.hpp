#ifndef UCS_HEADER
#define UCS_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class UCS : public Algorithm{
    private:
        map<string, int> distance;
    
    public:
        void search(State init_state);
};

#endif
