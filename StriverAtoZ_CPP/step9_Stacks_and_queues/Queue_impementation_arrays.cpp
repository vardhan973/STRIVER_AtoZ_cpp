#include <bits/stdc++.h>
using namespace std;
class Queue
{
public:
    int size = 10;
    int queue[10];
    int start = -1, end = -1;
    int currsize = 0;
    void push(int x)
    {
        if (currsize == size)
        {
            cout << "overflow"<<endl;
        }
        if (currsize == 0)
        {
            start = end = 0;
            queue[end] = x;
            currsize++;
        }else{
            end = (end + 1) % size;
            queue[end] = x;
            currsize++;
        }
    }
    void pop()
    {
        if (currsize==0){
            cout<<"Under flow"<<endl;
            return;
        }
        int el = queue[start];
        if(currsize==1){
            start=end=-1;
        }else{
            start = (start+1)%size;
        }
        currsize--;
    }
    int top()
    {
        if(currsize==0){
            cout<<"No element is there in the queue"<<endl;
            return -1;
        }
        return queue[start];
    }
    int queuesize(){
        return currsize;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(8);
    q.push(5);
    q.pop();
    cout << q.top()<<endl;
    q.pop();
    cout<<q.queuesize();
}