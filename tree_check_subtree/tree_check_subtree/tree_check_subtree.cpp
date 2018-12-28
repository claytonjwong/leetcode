/*
 
 CCI 4.10 Check sub-tree: T1 and T2 are two very large binary trees, with T1 much bigger than T2.  Create an algorithm to determine if T2 is a sub-tree of T1.
 
 A tree T2 is a sub-tree of T1 if there exists a node n in T1 such that the sub-tree of n is identical to T2.  That is, if you cut off the tree at node n, the two trees would be identical.
 
 I.E. -- compare tree / sub-tree by VALUE

 
 */



#include <iostream>

template<class T>
class Node{
public:
    Node(T val) : val{val}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class Solution{
public:
    static bool IsSubtree(Node<T>* a, Node<T>* b){
        if (!a || !b){
            return false;
        }
        
        // iterate through a using a pre-order traversal,
        // whenever the value of a's node equals the root value of b
        // start pre-order traversal of b, while the node values are equal, continue
        // traversing together,
        // also keep track of NULL nodes for structure equality, not just value equality
        
        return false;
    }
};


int main(int argc, const char * argv[]) {

    
    
    
    return 0;
}





