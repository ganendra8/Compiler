#include <iostream>
#include <string>
#include <vector>
using namespace std;

void generateAssembly(vector<string> threeAddress) {
    cout << "Assembly Code:\n";
    
    for(string line : threeAddress) {
        size_t eq = line.find('=');
        string lhs = line.substr(0, eq - 1);
        string rhs = line.substr(eq + 2);
        
        // Find operator in RHS
        char op = ' ';
        size_t opPos = 0;
        for(int i = 0; i < rhs.length(); i++) {
            if(rhs[i] == '+' || rhs[i] == '-' || 
               rhs[i] == '*' || rhs[i] == '/') {
                op = rhs[i];
                opPos = i;
                break;
            }
        }
        
        if(op != ' ') {
            string operand1 = rhs.substr(0, opPos - 1);
            string operand2 = rhs.substr(opPos + 2);
            
            cout << "MOV AX, " << operand1 << endl;
            
            switch(op) {
                case '+':
                    cout << "ADD AX, " << operand2 << endl;
                    break;
                case '-':
                    cout << "SUB AX, " << operand2 << endl;
                    break;
                case '*':
                    cout << "MUL " << operand2 << endl;
                    break;
                case '/':
                    cout << "DIV " << operand2 << endl;
                    break;
            }
            
            cout << "MOV " << lhs << ", AX" << endl;
        }
        else {
            // Simple assignment
            cout << "MOV AX, " << rhs << endl;
            cout << "MOV " << lhs << ", AX" << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<string> code;
    string line;
    
    cout << "Enter three-address code (end with 'done'):\n";
    while(getline(cin, line) && line != "done") {
        code.push_back(line);
    }
    
    generateAssembly(code);
    
    return 0;
}