#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToPrefix(string s) {
    stack<string> st;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (isOperator(c)) {
            string op2 = st.top(); st.pop();
            string op1 = st.top(); st.pop();
            string temp = c + op1 + op2;
            st.push(temp);
        } else {
            st.push(string(1, c));
        }
    }
    return st.top();
}

int main() {
    string postfix = "AB+CD-*";
    cout << postfixToPrefix(postfix);
    return 0;
}
