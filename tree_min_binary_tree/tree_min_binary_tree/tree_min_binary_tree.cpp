/*
 
 Write a program which maintains a binary tree.  The items with lesser value are on top.
 
 left <= n < right
 
 Insert 5:

 5
 
 
 Insert 1:
 
   5
  /
 1
 
 Insert 10
 
   5
  / \
 1   10
 
 
 Insert 5
 
    5
  /   \
 1     10
  \
   5
 
 When inserting, check the current node value
 if insert is less than or equal to the current node value,
    see if the node to the left is NULL, if so, insert there
    otherwise, set the left node as the current node and iterate again
 if insert is greater than the current node value,
    see if the node to the right is NULL, if so, insert there
    otherwise, set the right node as the current node and iterate
 
 */

#include <iostream>


using namespace std;

template<class T>
class Node{
public:
    Node(T val) : val{val}, parent{NULL}, left{NULL}, right{NULL} {}
    T val;
    Node* parent;
    
    // children
    Node* left;
    Node* right;
};

template<class T>
class NodeFactory{
public:
    static Node<T>* GenerateNode(T val) { return new Node<T>(val); }
};

template<class T>
class BinaryTree{
public:
    BinaryTree() : root{NULL} {}
    void Insert(Node<T>* node);
private:
    Node<T>* root;
};

template<class T>
void BinaryTree<T>::Insert(Node<T>* node){
    
    if (!root){
        root = node;
        return;
    }
    
        
    Node<T>* curr = root;
    
    while ( true ){
    
        // left
        if ( node->val <= curr->val ){
            
            // insert here and exit loop
            if (!curr->left){
                curr->left = node;
                node->parent = curr;
                break;
            }
            
            // iterate left
            else {
                curr = curr->left;
            }
            
        }
        
        // right ( node->val > curr->val )
        else {
            
            // insert here and exit loop
            if (!curr->right){
                curr->right = node;
                node->parent = curr;
                break;
            }
            
            // iterate right
            else {
                curr = curr->right;
            }
        }
    }
}


template<class T>
class MinHeap : public BinaryTree<T>{
public:
    MinHeap() {}
    void Insert(Node<T>* node){
        BinaryTree<T>::Insert(node);
        BubbleUp(node);
    }
    
private:
    
    void BubbleUp(Node<T>* node){
    
        if (!node || !node->parent){
            return;
        }
        
        while ( node && node->parent && node->val < node->parent->val ){
            
            T temp = node->parent->val;
            node->parent->val = node->val;
            node->val = temp;
            
            node = node->parent;
        }
    }
    
};


int main(int argc, const char * argv[]) {
    
    MinHeap<int> tree;

    
    tree.Insert(NodeFactory<int>::GenerateNode(5));
    tree.Insert(NodeFactory<int>::GenerateNode(1));
    tree.Insert(NodeFactory<int>::GenerateNode(5));
    tree.Insert(NodeFactory<int>::GenerateNode(10));
    
    
    return 0;
}










