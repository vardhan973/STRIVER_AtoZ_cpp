#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int size = 10;
    int stack[10];
    int currsize = 0;

    void push(int x)
    {
        if (currsize == size)
        {
            cout << "Overflow\n";
            return;
        }
        stack[currsize] = x;
        currsize++;
    }

    void pop()
    {
        if (currsize == 0)
        {
            cout << "Underflow\n";
            return;
        }
        currsize--;
    }

    int top()
    {
        if (currsize == 0)
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return stack[currsize - 1];
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(9);
    st.pop();
    cout << st.top();
}
