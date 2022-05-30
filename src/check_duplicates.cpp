#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void find_duplicates(vector<string> el){
    
    int bf_size = el.size();
    std::sort(el.begin(), el.end());
    for(int i = 0; i < el.size() - 1; i++) {
        if (el[i] == el[i + 1]) {
            el.erase(el.begin() + i);
            i--;
        }
    }
    int af_size = el.size();

    cout << "Before size: " << bf_size << " after size: " << af_size << " Dif: " << bf_size - af_size << endl;
}


int main(){
    // Create a text string, which is used to output the text file
    string myText;
    vector<string> el;

    ifstream MyReadFile("output.txt");
    while (getline (MyReadFile, myText)) {
        el.push_back(myText);
    }

    MyReadFile.close();

    find_duplicates(el);

    return 0;
}