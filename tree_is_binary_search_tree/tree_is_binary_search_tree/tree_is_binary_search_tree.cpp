/*
 
 CCI 4.5 Validate BST: Implement a function to check if a binary treei is a binary search tree
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Node{
public:
    Node(T val): val{val}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class NodeFactory{
public:
    static Node<T>* Generate(T val) { return new Node<T>(val); }
};


template<class T>
class Solution{
public:
    Solution() {}
    
    bool IsBinarySearchTree(Node<T>* node){
        vecNode.clear();
        InOrderTraversal(node);
        
        typedef typename vector<Node<T>*>::iterator vec_node_itr;
        
        vec_node_itr prev = vecNode.begin();
        vec_node_itr curr = vecNode.begin();
        
        while ( ++curr != vecNode.end() ){
            
            if ( (*prev)->val > (*curr)->val ){
                return false;
            }
            
            prev = curr;
        }
        
        return true;
    }
private:
    void InOrderTraversal(Node<T>* node){
        
        if (node){
            InOrderTraversal(node->left);
            vecNode.push_back(node);
            InOrderTraversal(node->right);
        }
    }
    vector<Node<T>*> vecNode;
};

int main(int argc, const char * argv[]) {

    Solution<int> solution;
    
    Node<int>* root = NodeFactory<int>::Generate(8);
    root->left = NodeFactory<int>::Generate(4);
    root->left->left = NodeFactory<int>::Generate(2);
    root->left->right = NodeFactory<int>::Generate(12);
    root->right = NodeFactory<int>::Generate(10);
    root->right->right = NodeFactory<int>::Generate(20);
    
    cout << "0 == " << solution.IsBinarySearchTree(root) << endl;
    
    return 0;
}




