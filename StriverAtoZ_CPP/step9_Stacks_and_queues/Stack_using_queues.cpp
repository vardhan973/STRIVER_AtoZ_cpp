#include <bits/stdc++.h>
using namespace std;

class StackUsingQueue {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q.front();
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    StackUsingQueue st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.push(40);
    cout << st.size() << endl;
}
