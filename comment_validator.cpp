#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    
    bool validComment = false;
    
    // Check for /* */ comment
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == '/' && s[i+1] == '*') {
            for(int j = i + 2; j < s.length() - 1; j++) {
                if(s[j] == '*' && s[j+1] == '/') {
                    validComment = true;
                    break;
                }
            }
            break;
        }
    }
    
    // Check for // comment
    if(!validComment) {
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '/' && s[i+1] == '/') {
                validComment = true;
                break;
            }
        }
    }
    
    if(validComment)
        cout << "VALID COMMENT" << endl;
    else
        cout << "INVALID COMMENT" << endl;
        
    return 0;
}
