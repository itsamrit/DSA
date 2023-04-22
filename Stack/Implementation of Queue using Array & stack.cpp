implementation of queue with // Time Complexity:  pop function: O(1)   push function: O(1) top function: O(1) size function: O(1)

#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int front;
    int back;
    int n;
    public:
    Queue(int size){
        arr = new int[size];
        front = -1;
        back = -1;
        n = size;
    }
    void push(int x){
        if(back == n-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        back++;
        arr[back] = x;
        if(front == -1){
            front++;
        }
    }
    void pop(){
        if(front == -1 || front>back){
            cout<<"No elements in queue"<<endl;
            return;
        }
        front++;
    }
    int top(){
        if(front == -1 || front>back){
            cout<<"No elements in queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool size(){
        if(front == -1 || front>back){
            return 0;
        }
        return back-front+1;
    }
};

// time complexity of pop function is O(1), push function is O(1), peek function is O(1) and empty function is O(1)
// implement queue using 2 stacks benefits no limitation of size of queue

class Queue{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }
    bool empty(){
        if(s1.empty() && s2.empty()){
            return true;
        }
        return false;
    }
};

// time complexity of pop is o(n) or amortized o(1), push is O(1) and empty is O(1)
// but why we are using 2 stack instead of array or vector because limitation of size of queue