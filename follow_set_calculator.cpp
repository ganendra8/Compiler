#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<char, vector<string>> grammar;
    map<char, set<char>> follow;
    
    int n;
    char start;
    cout << "Enter productions count and start symbol: ";
    cin >> n >> start;
    
    for(int i = 0; i < n; i++) {
        string prod;
        cin >> prod;
        grammar[prod[0]].push_back(prod.substr(3));
    }
    
    follow[start].insert('$');
    
    // Simple FOLLOW calculation
    for(int iter = 0; iter < 2; iter++) {
        for(auto& p : grammar) {
            for(string rhs : p.second) {
                for(int i = 0; i < rhs.length(); i++) {
                    char curr = rhs[i];
                    if(curr >= 'A' && curr <= 'Z') {
                        if(i + 1 < rhs.length()) {
                            char next = rhs[i + 1];
                            if(next >= 'a' && next <= 'z') {
                                follow[curr].insert(next);
                            }
                        } else {
                            for(char c : follow[p.first]) {
                                follow[curr].insert(c);
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "FOLLOW sets:\n";
    for(auto& f : follow) {
        cout << "FOLLOW(" << f.first << ") = { ";
        for(char c : f.second) cout << c << " ";
        cout << "}\n";
    }
    
    return 0;
}