#ifndef UCS_HEADER
#define UCS_HEADER

#include <map>
#include <stack>
#include <string>

#include "abstract_algorithm.hpp"

class UCS : public Algorithm{
    public:
        void search(State initial_state);
};

#endif
