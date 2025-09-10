// infix to prefix
#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Operator precedence
int priority(char c) {
    if (c == '^') return 3;              // highest
    if (c == '*' || c == '/') return 2;  // middle
    if (c == '+' || c == '-') return 1;  // lowest
    return -1;
}

// Convert Infix to Prefix
string infixToPrefix(string s) {
    // Step 1: reverse the infix expression
    reverse(s.begin(), s.end());

    // Step 2: swap '(' with ')'
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    // Step 3: convert reversed infix → postfix
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        // If operand → directly add
        if (isalnum(c)) {
            ans += c;
        }
        // If '(' → push to stack
        else if (c == '(') {
            st.push(c);
        }
        // If ')' → pop until '('
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // remove '('
        }
        // If operator
        else {
            if (c == '^') { // right-associative
                while (!st.empty() && priority(c) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            } else { // left-associative
                while (!st.empty() && priority(c) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    // Step 4: pop remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Step 5: reverse postfix to get prefix
    reverse(ans.begin(), ans.end());
    return ans;
}

// Driver code
int main() {
    string exp = "A*(B+C)/D";
    cout << "Infix:   " << exp << "\n";
    cout << "Prefix:  " << infixToPrefix(exp) << "\n";
    return 0;
}
