/*
 
 CCI CH 3.4: Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.
 
 */

#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    Node(T val) : val{val}, next{NULL} {}
    int val;
    Node<T>* next;
};

template<class T>
class Stack {
public:
    Stack() : head{NULL} {}
    
    void push(T val);
    T pop();
private:
    Node<T>* head;
};

template<class T>
void Stack<T>::push(T val){
    if (!head){
        head = new Node<T>(val);
    } else {
        Node<T>* prev_head = head;
        head = new Node<T>(val);
        head->next = prev_head;
    }
}

template<class T>
T Stack<T>::pop(){
    T result;
    if (!head){
        return NULL;
    } else {
        Node<T>* popped = head;
        result = popped->val;
        head = popped->next;
        delete popped;
    }
    return result;
}

template<class T>
class Queue {
public:
    void push(T val);
    T pop();
    
private:
    Stack<T> stack1;
    Stack<T> stack2;
};

template<class T>
void Queue<T>::push(T val){
    
    // pop all from stack1 and push onto stack2
    T temp = stack1.pop();
    while(temp){
        stack2.push(temp);
        temp = stack1.pop();
    }
    
    // add new entry onto bottom of stack1
    stack1.push(val);
    
    // pop all from stack2 back onto stack1
    temp = stack2.pop();
    while(temp){
        stack1.push(temp);
        temp = stack2.pop();
    }
}

template<class T>
T Queue<T>::pop(){
    T result = stack1.pop();
    return result;
}



/*

 Example: add X onto queue...
 
 
 Initial condition:
 
 stack1    stack2
 
 1
 2
 3
 
 1) pop from stack1 and push onto stack2
 
 stack1    stack2
 
            3
            2
            1
 
 2) push X onto bottom of stack1
 
 
 stack1    stack2
 
            3
            2
  X         1
 
 
 3) pop from stack2 and push back onto stack1
 
 stack1    stack2
 
    1
    2
    3
    X
 
 */

int main(int argc, const char * argv[]) {
    
    
    Queue<int> q;
    
    q.push(1);  // 1
    q.pop();    //
    q.push(1);  // 1
    q.pop();    //
    q.push(2);  // 2
    q.push(3);  // 3, 2
    q.pop();    // 3
    q.pop();    //
    q.push(3);  // 3
    q.pop();    //
    q.push(1);  // 1
    q.push(2);  // 2, 1
    q.pop();    // 2
    q.push(2);  // 2, 2
    q.push(3);  // 3, 2, 2
    q.push(4);  // 4, 3, 2, 2
    q.pop();    // 4, 3, 2
    q.push(4);  // 4, 4, 3, 2
    
    int r = q.pop();
    
    while(r){
        cout << r << endl;
        r = q.pop();
    }
    
    return 0;
}
