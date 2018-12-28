/*
 
 How would you design a stack which, in addition to push and pop, has a function which returns the minimum element?  Push, pop, and min should all operate in O(1) time.
 
 */

#include <iostream>

using namespace std;

template<class T>
class Node{
public:
    
    Node(T v) : val{v}, min_val{v}, next{NULL} {}
    
    void update_min(){
        if (!next){
            min_val = val;
        } else {
            min_val = min( val, next->min_val );
        }
    }
    void set_next(Node<T>* node){
        next = node;
        update_min();
    }
    
    
    T get_val(){ return val; }
    T get_min(){ return min_val; }
    Node<T>* get_next(){ return next; }
    
private:
    T val;
    T min_val;
    Node* next;
};

class MinStackException : public exception {

    virtual const char* what() const throw(){
        return "min stack exception, did you pop/peek an empty stack?";
    }
    
} min_stack_exception;

template<class T>
class MinStack {
public:
    MinStack() : head{NULL} {}
    void push(T v);
    T pop();
    T peek();
    T minimum();
    int size();
    bool empty();
private:
    Node<T>* head;
    int cnt;
};

template<class T>
void MinStack<T>::push(T v){
    if (!head){
        head = new Node<T>(v);
    } else {
        Node<T>* prev_head = head;
        head = new Node<T>(v);
        head->set_next(prev_head);
    }
    cnt++;
}

template<class T>
T MinStack<T>::pop(){
    T result;
    
    if (!head){
        throw min_stack_exception;
    } else {
        // get popped value
        Node<T>* popped = head;
        result = popped->get_val();
        
        // set new head of stack and free popped node
        head = popped->get_next();
        delete popped;
        cnt--;
    }
    return result;
}

template<class T>
T MinStack<T>::peek(){
    if (!head){
        throw min_stack_exception;
    } else {
        return head->get_val();
    }
}

template<class T>
T MinStack<T>::minimum(){
    if(!head){
        throw min_stack_exception;
    } else {
        return head->get_min();
    }
}

template<class T>
int MinStack<T>::size(){
    return cnt;
}

template<class T>
bool MinStack<T>::empty(){
    return size() == 0;
}

int main(int argc, const char * argv[]) {

    MinStack<int> stack;
    
    stack.push(0);
    stack.pop();
    stack.push(0);
    stack.push(1);
    stack.pop();
    stack.pop();
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    try{
        while ( !stack.empty() ){
            cout << endl << endl;
            cout << "And the min is: " << stack.minimum() << "   ";
            cout << "peek: " << stack.peek() << ", pop: " << stack.pop();
        }
    } catch( exception ex ) {} // pass
    
    stack.push(3);
    stack.push(2);
    stack.push(1);
    stack.push(0);
    
    try{
        while ( !stack.empty() ){
            cout << endl << endl;
            cout << "And the min is: " << stack.minimum() << "   ";
            cout << "peek: " << stack.peek() << ", pop: " << stack.pop();
        }
    } catch( exception ex ) {} // pass
    cout << endl << endl;
    
    return 0;
}




