#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Stack_linkedList
{
public:
    int size = 0;
    Node *topNode = nullptr;

    void push(int x)
    {
       Node* temp = new Node(x);
       temp->next = topNode;
       topNode = temp;
       size++;
    }

    void pop()
    {
        if(topNode==nullptr){
            cout<<"Underflow";
            return;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        topNode = topNode;
        delete temp;
        size--;
    }

    int top()
    {
       return topNode->data; 
    }

    int stacksize()
    {
        return size;
    }
};

int main()
{
    Stack_linkedList st;
    st.push(10);
    st.push(9);
    st.push(5);
    st.pop();
    cout << st.top() << endl;
    cout << st.stacksize() << endl;
}
