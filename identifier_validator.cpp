#include <iostream>
#include <string>
using namespace std;

bool isValidIdentifier(string s) {
    if(s.empty()) return false;
    
    // First character must be letter or underscore
    if(!((s[0] >= 'a' && s[0] <= 'z') || 
         (s[0] >= 'A' && s[0] <= 'Z') || 
         s[0] == '_')) {
        return false;
    }
    
    // Rest must be letters, digits, or underscores
    for(int i = 1; i < s.length(); i++) {
        if(!((s[i] >= 'a' && s[i] <= 'z') ||
             (s[i] >= 'A' && s[i] <= 'Z') ||
             (s[i] >= '0' && s[i] <= '9') ||
             s[i] == '_')) {
            return false;
        }
    }
    
    return true;
}

int main() {
    string s;
    cout << "Enter identifier: ";
    cin >> s;
    
    if(isValidIdentifier(s))
        cout << "VALID IDENTIFIER" << endl;
    else
        cout << "INVALID IDENTIFIER" << endl;
        
    return 0;
}