/*
 
 225. Implement Stack using Queues
 
 https://leetcode.com/problems/implement-stack-using-queues/description/
 
 Implement the following operations of a stack using queues.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 empty() -- Return whether the stack is empty.
 Notes:
 You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 
 */



#include <iostream>
#include <vector>

using namespace std;

class MyQueue {
public:
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        // pop from q to aux ( reverse order )
        while ( ! q.empty() ){
            aux.push_back( q.back() );
            q.pop_back();
        }
        aux.push_back(x);
        
        // pop back from aux to q ( forward oreder )
        while ( ! aux.empty() ){
            q.push_back( aux.back() );
            aux.pop_back();
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int result = q.back();
        q.pop_back();
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        return q.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return q.empty();
    }
    
private:
    vector<int> q; // forward order (queue)
    vector<int> aux; // reverse order
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, const char * argv[]) {

    
    MyQueue obj;
    obj.push(1);
    obj.push(2);
    cout << obj.peek() << endl;
    
    
    return 0;
}






