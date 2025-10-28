#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string prefixToPostfix(string s) {
    stack<string> st;
    int n = s.length();
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (isOperator(c)) {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string temp = op1 + op2 + c;
            st.push(temp);
        } else {
            st.push(string(1, c));
        }
    }
    return st.top();
}

int main() {
    string prefix = "*+AB-CD";
    cout << prefixToPostfix(prefix);
    return 0;
}
