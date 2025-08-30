#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tempCount = 1;

string newTemp() {
    return "t" + to_string(tempCount++);
}

string generateCode(string expr) {
    vector<string> code;
    string result = expr;
    
    // Handle expressions with operators
    for(int i = 0; i < result.length(); i++) {
        if(result[i] == '+' || result[i] == '-' || 
           result[i] == '*' || result[i] == '/') {
            
            string left = "";
            string right = "";
            char op = result[i];
            
            // Get left operand
            int j = i - 1;
            while(j >= 0 && result[j] != ' ') {
                left = result[j] + left;
                j--;
            }
            
            // Get right operand  
            j = i + 1;
            while(j < result.length() && result[j] != ' ') {
                right += result[j];
                j++;
            }
            
            string temp = newTemp();
            code.push_back(temp + " = " + left + " " + op + " " + right);
            
            // Replace expression with temp
            string oldExpr = left + op + right;
            size_t pos = result.find(oldExpr);
            if(pos != string::npos) {
                result.replace(pos, oldExpr.length(), temp);
            }
            i = 0; // Restart scan
        }
    }
    
    // Print generated code
    for(string line : code) {
        cout << line << endl;
    }
    
    return result;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);
    
    cout << "\nIntermediate Code:\n";
    string result = generateCode(expr);
    
    // Handle assignment if present
    size_t pos = expr.find('=');
    if(pos != string::npos) {
        string var = expr.substr(0, pos);
        cout << var << "= " << result.substr(pos + 1) << endl;
    }
    
    return 0;
}