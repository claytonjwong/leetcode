/*
 
 CCI CH 12.8: Copy Node: Write a method that takes a pointer to a Node structure as a parameter and returns a complete copy of the passed in data structure.  The Node data structure contains two pointers to other Nodes.
 
 */

#include <iostream>
#include <unordered_map>

using namespace std;

template<class T>
class Node{
public:
    Node(T val) : val{val}, a{NULL}, b{NULL} {}
    
    T val;
    Node<T>* a;
    Node<T>* b;
};

template<class T>
class Solution{
public:
    
    Node<T>* copy(Node<T>* node){
        
        if (!node){
            return NULL;
        }
        
        //
        // if we have already visited this node, return the copy
        //
        if (mapping.find(node) != mapping.end()){
            return mapping[node];
        }
        
        //
        // this node has NOT been visisted,
        //
        // create a new copy of it keep track of the old/new copy through the hash mapping
        // the old node address is the key and the new node address is the value of the hash mapping
        //
        // recusively copy the node pointers a and b in this same fashion
        //
        mapping[node] = new Node<T>(node->val);
        mapping[node]->a = copy(node->a);
        mapping[node]->b = copy(node->b);
        return mapping[node];

    }
    
private:
    
    unordered_map<Node<T>*, Node<T>*> mapping; // key is old node, val is new node copy
    
};



int main(int argc, const char * argv[]) {

    
    Node<int>* n = new Node<int>(69);
    n->a = new Node<int>(1);
    n->a->a = new Node<int>(2);
    n->a->a->a = new Node<int>(3);
    n->b = new Node<int>(101);
    n->b->b = new Node<int>(102);
    n->b->b->b = new Node<int>(103);
    
    Solution<int> solution;
    Node<int>* n2 = solution.copy(n);
    
    return 0;
}





