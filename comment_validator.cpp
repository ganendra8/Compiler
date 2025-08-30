#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    
    int state = 0;
    
    for(int i = 0; i < s.length(); i++) {
        if(state == 0) {
            if(s[i] == '/' && i+1 < s.length() && s[i+1] == '*') {
                state = 1;
                i++; // Skip next character
            }
        }
        else if(state == 1) {
            if(s[i] == '*' && i+1 < s.length() && s[i+1] == '/') {
                state = 2;
                i++; // Skip next character
            }
        }
    }
    
    if(state == 2)
        cout << "VALID COMMENT" << endl;
    else
        cout << "INVALID COMMENT" << endl;
        
    return 0;
}