/*
 
 CCI 4.4  Check Balanced: Implement a function to check if a binary tree is balanced.  For the purposes of this question, a balance tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
 
 
 */

#include <iostream>
#include <cmath>


using namespace std;

template<class T>
class Node {
public:
    Node(T val) : val{val}, left{NULL}, right{NULL} {}
    T val;
    Node<T>* left;
    Node<T>* right;
};

template<class T>
class Solution {
public:
    bool IsBalanced(Node<T>* node){
        
        return depth(node) != -1;
    }
    
    int depth(Node<T>* node){
        
        if (!node) { return 0; }
        
        int left = depth(node->left);
        if (left==-1){
            return -1;
        }
        
        int right = depth(node->right);
        if (right==-1){
            return -1;
        }
        
        if ( abs( left-right ) > 1 ){
            return -1;
        }
        
        return 1 + max( left,right );
    }
    

};

int main(int argc, const char * argv[]) {

    /*
     
     
             0
          /     \
        1         2
       / \       / \
      11  22     3  4
      / \    \       \
     111 222  33      5
     /                 \
   1111                 6
     
     
     */
    
    
    Node<int>* root = NULL;
    
    root = new Node<int>(0);
//    root->left = new Node<int>(1);
//    root->left->left = new Node<int>(11);
//    root->left->right = new Node<int>(22);
//    root->left->right->right = new Node<int>(33);
//    root->left->left->left = new Node<int>(111);
//    root->left->left->right = new Node<int>(222);
//    root->left->left->left->left = new Node<int>(1111);
    
    root->right = new Node<int>(2);
    root->right->left = new Node<int>(3);
    root->right->right = new Node<int>(4);
    root->right->right->right = new Node<int>(5);
    root->right->right->right->right = new Node<int>(6  );
    
    Solution<int> solution;
    cout << "IsBalanced? false 0: " << solution.IsBalanced(root) << endl;
    
    return 0;
}





