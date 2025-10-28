#include <bits/stdc++.h>
using namespace std;

int priority(char a) {
    if (a == '^')
        return 3;
    else if (a == '*' || a == '/')
        return 2;
    else if (a == '+' || a == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string a) {
    string ans = "";
    stack<char> st;
    for (int i = 0; i < a.length(); i++) {
        char c = a[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            ans += c;
        else if (c == '(')
            st.push(c);
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string infixToPrefix(string s) {
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int main() {
    string exp = "((A+B)*(C-D))";
    cout << infixToPrefix(exp);
    return 0;
}
