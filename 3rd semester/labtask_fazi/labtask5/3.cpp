#include <iostream>
#include <string>

using namespace std;

bool isMatching(char open, char close) {
    if (open == '(' && close == ')') {
        return true;
    } else if (open == '[' && close == ']') {
        return true;
    } else if (open == '{' && close == '}') {
        return true;
    }
    return false;
}

bool isBalanced(string ex) {
    int size = 0;

    for (char c : ex) {
        if (c == '(' || c == '[' || c == '{') {
            size++;
        } else if (c == ')' || c == ']' || c == '}') {
            if (size == 0 || !isMatching(ex[size - 1], c)) {
                return false;
            }
            size--;
        }
    }

    return size == 0;
}

int main() {
    string e = "([{}])";
    if (isBalanced(e)) {
        cout << "The expression \"" << e << "\" is balanced." << endl;
    } else {
        cout << "The expression \"" << e << "\" is not balanced." << endl;
    }

    return 0;
}
