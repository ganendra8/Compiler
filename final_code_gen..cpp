#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    string op, arg1, arg2, result;
    while (input >> op >> arg1 >> arg2 >> result) {
        if (op == "+") {
            output << "MOV R0," << arg1 << "\n";
            output << "ADD R0," << arg2 << "\n";
            output << "MOV " << result << ",R0\n";
        } else if (op == "-") {
            output << "MOV R0," << arg1 << "\n";
            output << "SUB R0," << arg2 << "\n";
            output << "MOV " << result << ",R0\n";
        } else if (op == "*") {
            output << "MOV R0," << arg1 << "\n";
            output << "MUL R0," << arg2 << "\n";
            output << "MOV " << result << ",R0\n";
        } else if (op == "/") {
            output << "MOV R0," << arg1 << "\n";
            output << "DIV R0," << arg2 << "\n";
            output << "MOV " << result << ",R0\n";
        } else if (op == "=") {
            output << "MOV R0," << arg1 << "\n";
            output << "MOV " << result << ",R0\n";
        }
    }

    input.close();
    output.close();
    cout << "Final code generated in output.txt" << endl;

    return 0;
}
