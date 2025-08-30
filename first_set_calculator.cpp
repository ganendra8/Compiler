#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSets;

void calculateFirst(char symbol) {
    if(firstSets[symbol].size() > 0) return; // Already calculated
    
    for(string production : grammar[symbol]) {
        for(int i = 0; i < production.length(); i++) {
            char first = production[i];
            
            // Terminal symbol
            if(first >= 'a' && first <= 'z') {
                firstSets[symbol].insert(first);
                break;
            }
            // Non-terminal
            else if(first >= 'A' && first <= 'Z') {
                calculateFirst(first);
                
                // Add first of non-terminal (except epsilon)
                for(char c : firstSets[first]) {
                    if(c != 'e') firstSets[symbol].insert(c);
                }
                
                // If first doesn't contain epsilon, stop
                if(firstSets[first].find('e') == firstSets[first].end()) {
                    break;
                }
            }
            
            // If we processed all symbols and all had epsilon
            if(i == production.length() - 1) {
                firstSets[symbol].insert('e'); // epsilon
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;
    
    cout << "Enter productions (format: A->abc):\n";
    for(int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        
        char lhs = prod[0];
        string rhs = prod.substr(3); // Skip "A->"
        
        grammar[lhs].push_back(rhs);
    }
    
    // Calculate FIRST for all non-terminals
    for(auto& p : grammar) {
        calculateFirst(p.first);
    }
    
    // Display results
    cout << "\nFIRST sets:\n";
    for(auto& p : firstSets) {
        cout << "FIRST(" << p.first << ") = { ";
        for(char c : p.second) {
            if(c == 'e') cout << "ε ";
            else cout << c << " ";
        }
        cout << "}\n";
    }
    
    return 0;
}