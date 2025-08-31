#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cctype>
using namespace std;

int tempCount = 1;
string newTemp() { return "t" + to_string(tempCount++); }

struct Op { string left, right, res, oper; };

int precedence(char op) {
    return (op == '*' || op == '/') ? 2 :
           (op == '+' || op == '-') ? 1 : 0;
}

vector<Op> generateIntermediate(const string& expr) {
    stack<char> ops;
    stack<string> vals;
    vector<Op> code;
    
    for (size_t i = 0; i < expr.size(); ++i) {
        if (isspace(expr[i])) continue;
        if (isalnum(expr[i])) {
            string var = "";
            while (i < expr.size() && isalnum(expr[i])) var += expr[i++];
            --i;
            vals.push(var);
        } else if (expr[i] == '(') ops.push('(');
        else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                string right = vals.top(); vals.pop();
                string left = vals.top(); vals.pop();
                string temp = newTemp();
                code.push_back({left, right, temp, string(1, ops.top())});
                vals.push(temp);
                ops.pop();
            }
            ops.pop(); // pop '('
        } else { // operator
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[i])) {
                string right = vals.top(); vals.pop();
                string left = vals.top(); vals.pop();
                string temp = newTemp();
                code.push_back({left, right, temp, string(1, ops.top())});
                vals.push(temp);
                ops.pop();
            }
            ops.push(expr[i]);
        }
    }

    while (!ops.empty()) {
        string right = vals.top(); vals.pop();
        string left = vals.top(); vals.pop();
        string temp = newTemp();
        code.push_back({left, right, temp, string(1, ops.top())});
        vals.push(temp);
        ops.pop();
    }

    return code;
}

int main() {
    string expr;
    cout << "Enter expression: ";
    getline(cin, expr);

    // Split assignment
    size_t pos = expr.find('=');
    string lhs = expr.substr(0, pos);
    string rhs = expr.substr(pos + 1);

    vector<Op> code = generateIntermediate(rhs);

    cout << "\nIntermediate Code:\n";
    for (auto &c : code)
        cout << c.res << " := " << c.left << c.oper << c.right << endl;

    cout << lhs << " := " << (code.empty() ? rhs : code.back().res) << endl;

    return 0;
}
