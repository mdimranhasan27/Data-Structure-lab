#include <bits/stdc++.h>
using namespace std;

// Helper: precedence of operators
int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3; // highest
    return 0;
}

// Helper: check if character is operator
bool isOperator(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

// Print stack contents (bottom -> top)
string stackToString(const vector<char>& st) {
    if (st.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < st.size(); ++i) {
        s.push_back(st[i]);
        if (i+1 < st.size()) s += ' ';
    }
    s += "]";
    return s;
}

int main() {
    string infix;
    cout << "Enter infix expression (operands single letters/digits):\n";
    getline(cin, infix);

    vector<char> st;         // manual stack (don't use std::stack)
    string postfix = "";     // resulting postfix expression

    cout << "\nStep-by-step conversion:\n";
    cout << "------------------------------------------------------------\n";
    cout << "Idx | Char | Action                             | Stack | Postfix\n";
    cout << "------------------------------------------------------------\n";

    for (size_t i = 0; i < infix.size(); ++i) {
        char ch = infix[i];

        // skip spaces
        if (ch == ' ') continue;

        string action;

        if (isalnum((unsigned char)ch)) { // operand (letter or digit)
            postfix.push_back(ch);
            action = "Add operand to postfix";
        }
        else if (ch == '(') {
            st.push_back(ch);
            action = "Push '(' onto stack";
        }
        else if (ch == ')') {
            // pop until '('
            bool found = false;
            while (!st.empty()) {
                char top = st.back();
                st.pop_back();
                if (top == '(') { found = true; break; }
                postfix.push_back(top);
                // we record pop actions below as part of the loop's state print
            }
            action = "Pop until '(' (and discard '(')";
            if (!found) action += "  [WARNING: mismatched parentheses]";
        }
        else if (isOperator(ch)) {
            // For right-associative '^' we handle equality differently
            while (!st.empty() && isOperator(st.back())) {
                char top = st.back();
                // if current op is '^' (right-assoc), pop only when prec(top) > prec(ch)
                // else (left-assoc) pop when prec(top) >= prec(ch)
                if ( (ch == '^' && prec(top) > prec(ch)) ||
                     (ch != '^' && prec(top) >= prec(ch)) ) {
                    // pop top to postfix
                    st.pop_back();
                    postfix.push_back(top);
                } else break;
            }
            st.push_back(ch);
            action = string("Push operator '") + ch + "' (after popping higher/equal prec)";
        }
        else {
            action = string("Ignored/unrecognized char '") + ch + "'";
        }

        // Print row for this character (index, char, action, stack, postfix)
        cout << setw(3) << i << " | "
             << setw(4) << ch << " | "
             << setw(35) << left << action << " | "
             << setw(5) << right << stackToString(st) << " | "
             << postfix << "\n";
    }

    // After processing all input, pop remaining operators
    cout << "------------------------------------------------------------\n";
    cout << "Now emptying remaining operators from stack to postfix:\n";
    while (!st.empty()) {
        char top = st.back();
        st.pop_back();
        if (top == '(' || top == ')') {
            cout << "   [Discarding parentheses " << top << "]\n";
            continue;
        }
        postfix.push_back(top);
        cout << "   Popped '" << top << "' -> Postfix now: " << postfix
             << " | Stack: " << stackToString(st) << "\n";
    }

    cout << "------------------------------------------------------------\n";
    cout << "Final postfix: " << postfix << "\n";
    return 0;
}
