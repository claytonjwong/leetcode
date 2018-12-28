/*
 
 155. Min Stack
 
 https://leetcode.com/problems/min-stack/description/
 
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 
 Example:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> Returns -3.
 minStack.pop();
 minStack.top();      --> Returns 0.
 minStack.getMin();   --> Returns -2.
 
 */

#include <iostream>
#include <vector>

using namespace std;


class MinStack {
public:
    
    void push(int x) {
        if ( min.empty() || x <= min.back() ){
            min.push_back(x);
        }
        stack.push_back(x);
    }
    
    void pop() {
        if ( stack.back() == min.back() ){
            min.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return min.back();
    }
            
private:
    vector<int> stack;
    vector<int> min;
};




int main(int argc, const char * argv[]) {

    MinStack s;
    
    s.push(2);
    s.push(0);
    s.push(3);
    s.push(0);
    cout << "min 0 == " << s.getMin() << endl;
    s.pop();
    cout << "min 0 == " << s.getMin() << endl;
    
    return 0;
}



