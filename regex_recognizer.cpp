#include <iostream>
#include <string>
using namespace std;

bool checkPattern(string s) {
    int n = s.length();
    
    // Check for a* (zero or more 'a's)
    bool isA = true;
    for(char c : s) {
        if(c != 'a') {
            isA = false;
            break;
        }
    }
    if(isA) return true;
    
    // Check for a*b* (zero or more 'a's followed by zero or more 'b's)
    bool isAB = true;
    bool seenB = false;
    for(char c : s) {
        if(c == 'b') seenB = true;
        else if(c == 'a' && seenB) {
            isAB = false;
            break;
        }
        else if(c != 'a' && c != 'b') {
            isAB = false;
            break;
        }
    }
    if(isAB) return true;
    
    // Check for "abb"
    if(s == "abb") return true;
    
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    
    if(checkPattern(s))
        cout << "ACCEPTED" << endl;
    else
        cout << "REJECTED" << endl;
        
    return 0;
}