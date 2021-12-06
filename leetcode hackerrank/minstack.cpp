#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int minNum;
        int data;
        Node *next;
        Node(){}
        Node(int val){
            this->data = val;
            *next = MinStack::top;
            this->minNum = min(MinStack::top->minNum, val);
        }
    };
    Node top;

    MinStack::MinStack() {
        
    }
    MinStack::Node(){

    }
    
    void push(int val) {
        
    }
    
    void pop() {
        
    }
    
    int top() {
        
    }
    
    int getMin() {
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */