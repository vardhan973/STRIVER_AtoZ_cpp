#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue_linkedlist {
public:
    int size = 0;
    Node* start = nullptr;
    Node* end = nullptr;

    void push(int x) {
        Node* temp = new Node(x);
        if (start == nullptr) {
            start = end = temp;
        } else {
            end->next = temp;
            end = temp;
        }
        size++;
    }

    void pop() {
        if (start == nullptr) {
            cout << "No element is there" << endl;
            return;
        }
        Node* temp = start;
        start = start->next;
        delete temp;
        size--;
        if (start == nullptr) end = nullptr;
    }

    int front() {
        if (start == nullptr) {
            cout << "No element is there" << endl;
            return -1;
        }
        return start->data;
    }

    int queuesize() {
        return size;
    }
};

int main() {
    Queue_linkedlist q;
    q.push(10);
    q.push(8);
    q.pop();
    cout << q.front() << endl;
    q.push(5);
    q.pop();
    cout << q.queuesize() << endl;
    cout << q.front() << endl;
    return 0;
}
