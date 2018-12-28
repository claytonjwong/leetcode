/*
 
 Write a program to sort a stack such that smallest items are on the top.  You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array).  The stack supports the following operations: push, pop, peek, and isEmpty
 
 */

#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    Node(T val) : val{val}, next{NULL} {}
    T val;
    Node<T>* next;
};

template<class T>
class Stack{
public:
    Stack() : head{NULL} {}
    bool empty() { return head == NULL; }
    void push(T val);
    T peek();
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
T Stack<T>::peek(){
    T result;
    
    if (!head){
        return NULL;
    } else {
        result = head->val;
    }
    
    return result;
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
class SortedStack : public Stack<T> {
public:
    SortedStack() : aux{new Stack<T>()}  {}
    void pushSorted(T val);
private:
    Stack<T>* aux;

};

template<class T>
void SortedStack<T>::pushSorted(T val){
    
    // pop off from the head into aux while val > peek()
    while (this->peek() && val > this->peek()){
        aux->push(this->pop());
    }
    
    // push val
    this->push(val);
    
    // push from aux back into head
    val = aux->pop();
    while(val){
        this->push(val);
        val = aux->pop();
    }
    
}

int main(int argc, const char * argv[]) {
    
    SortedStack<int>* stack = new SortedStack<int>();
    
    stack->pushSorted(1);
    stack->pushSorted(2);
    stack->pushSorted(3);
    
    int val = stack->pop();
    while(val){
        cout << val << endl;
        val = stack->pop();
    }
    cout << endl;

    stack->push(1);
    stack->push(2);
    stack->push(3);
    
    val = stack->pop();
    while(val){
        cout << val << endl;
        val = stack->pop();
    }
    cout << endl;

    
    return 0;
}
