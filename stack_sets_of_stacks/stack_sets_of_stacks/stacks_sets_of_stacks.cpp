/*
 
 Image a (literal) stack of plates.  If the stack gets too high, it might topple.  Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.  Implement a data structure StackSet that mimics this.  StackSet should be composed of several stacks and should create a new stack once the previous one exceeds capacity.  StackSet.push() and StackSet.pop() should behave identically to a single stack (that is pop() should return the same values as it would if there were just a single stack).
 
 FOLLOW UP
 
 Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.
 
 */

#include <iostream>


using namespace std;



template <class T>
class Node{
public:
    Node(T v);

    T val;
    Node<T>* next;
};

template <class T>
Node<T>::Node(T v){
    val = v;
    next = NULL;
}

template <class T>
class NodeList{
public:
    NodeList(T val);

    Node<T>* head_node;
    int node_cnt;
    
    NodeList<T>* next_node_list;
};


template <class T>
NodeList<T>::NodeList(T val){
    
    // set head node to new node
    head_node = new Node<T>(val);
    node_cnt = 1;
    
    // set next_list to the next node list
    next_node_list = NULL;
}


class EmptyStackSetException: public exception
{
    virtual const char* what() const throw()
    {
        return "EmptyStackSetException occurred: new failed or pop()/peek() inovked on empty stack";
    }
} stackset_ex;


template <class T>
class StackSet {
public:
    
    static const int DEFAULT_CAPACITY = 2;
    
    StackSet(void);
    StackSet(int capacity);

    
    void push(T val){
        
        try{
        
            if ( stack_list == NULL ){
            
                stack_list = new NodeList<T>(val);
                
            
            } else {
            
                
                if ( stack_list->node_cnt == stack_capacity ){  // if at capcacity,
                                                                // add val onto new stack list
                    NodeList<T>* temp = stack_list;
                    stack_list = new NodeList<T>(val);
                    stack_list->next_node_list = temp;
                    
                } else { // add new node onto the existing stack list
                
                    Node<T>* new_node = new Node<T>(val);
                    new_node->next = stack_list->head_node;
                    stack_list->head_node = new_node;
                    stack_list->node_cnt++;
                }
                


            }
            
        } catch(std::bad_alloc& exc) {
            
            throw stackset_ex;
        }
    }
    
    
    T pop(){
        
        if ( stack_list && stack_list->head_node ){

            // pop head off the stack
            Node<T>* popped_node = stack_list->head_node;
            stack_list->head_node = stack_list->head_node->next;
            stack_list->node_cnt--;
            
            // free the popped head
            T return_value = popped_node->val;
            delete popped_node;
            
            // check for empty stack list, if so, try to point towards next stack list
            if ( stack_list->head_node == NULL ){
                stack_list = stack_list->next_node_list;
            }
            
            
            return return_value;

        } else {
            
            throw stackset_ex;
            
        }
    }

    
    T peek(){
        
        if ( stack_list && stack_list->head ){
            
            return stack_list->head->val;
            
        } else {
            
            throw stackset_ex;
            
        }
    }
    
    bool isEmpty(){
        return stack_list == NULL;
    }

private:
    
    NodeList<T>* stack_list;
    int stack_capacity;
};

template <class T>
StackSet<T>::StackSet(void){
    stack_list = NULL;
    stack_capacity = DEFAULT_CAPACITY;
}

template <class T>
StackSet<T>::StackSet(int capacity){
    stack_list = NULL;
    stack_capacity = capacity;
}

int main(int argc, const char * argv[]) {
    
    int val;
    //StackSet<int>* ss = new StackSet<int>(StackSet<int>::DEFAULT_CAPACITY);
    StackSet<int>* ss = new StackSet<int>();
    
    ss->push(0);
    ss->pop();
    ss->push(0);
    ss->push(1);
    ss->push(2);
    ss->push(3);
    ss->push(4);
    ss->push(5);
    ss->pop();
    ss->push(5);
    ss->push(6);
    ss->push(7);
    ss->push(8);
    ss->pop();
    ss->pop();
    ss->pop();
    ss->push(6);
    ss->push(7);
    ss->push(8);
    
    while ( ! ss->isEmpty() ){
    
        val = ss->pop();
        cout << "Popped node value: " << val << endl << endl;
    }

    try{
        
        val = ss->pop();
        cout << "Popped node value: " << val << endl << endl;
        
    } catch ( EmptyStackSetException ex ) {
        
        cout << "Exception caught, this is expected since we popped off an empty list:" << endl << endl;
    }
    
    return 0;
}
