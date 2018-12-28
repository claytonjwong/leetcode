/*
 
 114. Flatten Binary Tree to Linked List
 
 https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 
 Given a binary tree, flatten it to a linked list in-place.
 
 For example,
 Given
 
     1
    / \
   2   5
  / \   \
 3   4   6
 
 The flattened tree should look like:
 
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 
 */




#include <iostream>



struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val) : val{val}, left{NULL}, right{NULL} {}
};


class Solution{
public:
    void flatten(TreeNode* root){
        
        TreeNode* curr = root;
        
        // make all left subtrees right subtrees
        while (curr){
            
            if (curr->left){
                
                // save previous right subtree
                TreeNode* prev_right = curr->right;
                
                // set right subtree to left subtree
                curr->right = curr->left;
                
                // set left subtree NULL
                curr->left = NULL;
                
                // set right-most right to the previous right subtree
                TreeNode* rightmost  = curr;
                while (rightmost->right){
                    rightmost = rightmost->right;
                }
                rightmost->right = prev_right;
            }
            
            curr = curr->right; // iterate to the right
        }
        
    }
};

int main(int argc, const char * argv[]) {

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    Solution solution;
    solution.flatten(root);
    
    
    
    return 0;
}





