#include <iostream>
#include <stack>
#include <string>

using namespace std;

int postfixExpression(string expression) {
    stack<int> operands;

    for (char c : expression) {
        if (isdigit(c)) {
            operands.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            switch (c) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }
    return operands.top();
}

int main() {
    string expression = "23*5+";
    int result = postfixExpression(expression);
    cout << "  RESULT  " << expression << " = " << result << endl;

    return 0;
}
