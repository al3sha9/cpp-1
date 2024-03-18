#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool balanced(string expression) {
    stack<char> parentheses;

    for (char c : expression) {
        if (c == '(') {
            parentheses.push(c);
        } else if (c == ')') {
            if (parentheses.empty() || parentheses.top() != '(') {
                return false; 
            }
            parentheses.pop();
        }
    }

    return parentheses.empty(); 
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (balanced(expression)) {
        cout << "The expression has balanced!" << endl;
    } else {
        cout << "The expression does not balanced" << endl;
    }

    return 0;
}
