#ifndef ALGORITHM_HEADER
#define ALGORITHM_HEADER

#include <map>

class Algorithm {
    
    protected:
        int expanded_states = 0;
        map<string, int> found;
        map<string, string> parents; // <'str1', 'str2'> str1 is a child of str2
    
    public:    

        virtual void search(State init_state);

        void print_path(stack<string> path);
        void mark_as_found(string state_key);
        bool state_was_found(string state_key);
        stack<string> retrive_path(State initial_state);
        int get_expanded_states();
};

#endif
