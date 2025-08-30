#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

int main() {
    // Parsing table: M[non-terminal][terminal] = production
    map<pair<char,char>, string> table;
    
    cout << "Enter parsing table entries (format: A a S->AB, end with 'done'):\n";
    string input;
    while(cin >> input && input != "done") {
        char nt = input[0];    // non-terminal
        char t = input[2];     // terminal
        string prod = input.substr(4); // production
        table[{nt, t}] = prod;
    }
    
    cout << "Enter input string: ";
    string str;
    cin >> str;
    str += '$';  // Add end marker
    
    stack<char> stk;
    stk.push('$');
    stk.push('S');  // Start symbol
    
    int i = 0;
    cout << "\nParsing steps:\n";
    
    while(!stk.empty() && i < str.length()) {
        char top = stk.top();
        char curr = str[i];
        
        cout << "Stack: ";
        stack<char> temp = stk;
        string stackStr = "";
        while(!temp.empty()) {
            stackStr = temp.top() + stackStr;
            temp.pop();
        }
        cout << stackStr << ", Input: " << str.substr(i) << endl;
        
        // Match terminal
        if(top == curr) {
            stk.pop();
            i++;
        }
        // Apply production
        else if(top >= 'A' && top <= 'Z') {
            if(table.find({top, curr}) != table.end()) {
                stk.pop();
                string prod = table[{top, curr}];
                
                // Push production in reverse
                for(int j = prod.length() - 1; j >= 0; j--) {
                    if(prod[j] != 'e') stk.push(prod[j]);
                }
                
                cout << "Apply: " << top << " -> " << prod << endl;
            } else {
                cout << "ERROR: No entry in table\n";
                break;
            }
        }
    }
    
    if(stk.top() == '$' && str[i-1] == '$') {
        cout << "ACCEPTED\n";
    } else {
        cout << "REJECTED\n";
    }
    
    return 0;
}