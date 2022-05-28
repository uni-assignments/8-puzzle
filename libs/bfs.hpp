#ifndef BFS_HEADER

#include <map>
#include <stack>
#include <string>

class BFS {
    private:
        map<string, bool> visited;
        map<string, string> parents;

    public:
        BFS();

        void search(State initial_state);
        void mark_as_visited(string state_key);
        bool state_was_visited(string state_key);
        stack<string> retrive_path(State initial_state);
};

#endif
