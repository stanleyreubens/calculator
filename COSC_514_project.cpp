#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void parseAndCalculate(const string &input) {
    stringstream ss(input);
    char operation;
    double num1, num2, result;

    // Parse the input in the format: number operation number
    if (ss >> num1 >> operation >> num2) {
        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Error: Invalid operation." << endl;
        }
    } else {
        cout << "Error: Invalid input format. Please use 'number operation number' format." << endl;
    }
}

int main() {
    string input;

    cout << "Simple Calculator on FreeBSD" << endl;
    cout << "Enter calculation (e.g., 5 + 3 or 8.5 * 2.1):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit" || input == "quit") {
            cout << "Exiting calculator." << endl;
            break;
        }

        parseAndCalculate(input);
    }

    return 0;
}
