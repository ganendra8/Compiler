#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;
    
    set<int> states = {0}; // Start with state 0
    
    for(char c : s) {
        set<int> newStates;
        
        for(int state : states) {
            if(state == 0) {
                newStates.insert(0); // Stay in 0 on any input
                if(c == '1') newStates.insert(1); // Go to 1 on '1'
            }
            else if(state == 1) {
                if(c == '0') newStates.insert(2); // Go to 2 on '0'
                if(c == '1') newStates.insert(1); // Stay in 1 on '1'
            }
            else if(state == 2) {
                newStates.insert(2); // Stay in accepting state
            }
        }
        states = newStates;
    }
    
    if(states.count(2) > 0)
        cout << "ACCEPTED" << endl;
    else
        cout << "REJECTED" << endl;
        
    return 0;
}