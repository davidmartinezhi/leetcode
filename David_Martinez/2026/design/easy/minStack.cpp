#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    /*
    21 min left
    
    constraints
        - range of values that each number can have? int_min and int_max
        - will the methods be called on a empty stack? no
        - how many calls will be made? 30k at most
        
    first in, last out
    
    top is o(1)
    pop() is o(1)
    getMin is o(1)
    
    getMin is the tricky part.
    
    i must have the min precalculated, instead of looking for it.
    
    es muy buena idea, guardar con cada valor del stack, cual es el min hasta ese punto.
    
    <3,2>
    <2,2>
    */
private:
    stack<pair<int, int>> s; // actual value, min value seen until now

public:
    MinStack() {
    }
    
    void push(int value) {
        if(s.empty()){
            s.push(make_pair(value, value));
        }else{
            s.push(make_pair(value, min(value, s.top().second)));
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
