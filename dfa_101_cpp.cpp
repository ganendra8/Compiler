#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;
    
    int state = 0;
    
    for(char c : s) {
        if(state == 0) {
            if(c == '1') state = 1;
        }
        else if(state == 1) {
            if(c == '0') state = 2;
            // if c == '1', stay in state 1
        }
        else if(state == 2) {
            if(c == '1') state = 3;
            else state = 0;
        }
        else if(state == 3) {
            if(c == '1') state = 1;
            else state = 2;
        }
    }
    
    if(state == 3) 
        cout << "ACCEPTED" << endl;
    else 
        cout << "REJECTED" << endl;
        
    return 0;
}