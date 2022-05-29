#ifndef ALGORITHM_HEADER
#define ALGORITHM_HEADER

#include <map>

class Algorithm {
    
    protected:
        map<string, bool> visited;
        map<string, string> parents; // <'str1', 'str2'> str1 is a child of str2
    
    public:    

        virtual void search(State initial_state);

        void print_path(stack<string> path);
        void mark_as_visited(string state_key);
        bool state_was_visited(string state_key);
        stack<string> retrive_path(State initial_state);
};

#endif
