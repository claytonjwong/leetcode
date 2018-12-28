/*
 
 110. Balanced Binary Tree
 
 https://leetcode.com/problems/balanced-binary-tree/description/
 
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 */

#include <iostream>
#include <cmath>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};



class Solution{
public:
    bool isBalanced(TreeNode* root){
        return depth(root) != -1;
    }
    
    int depth(TreeNode* node){
        
        if (!node) { return 0; }
        
        int left = depth(node->left);
        if (left==-1){ return -1; }
        
        int right = depth(node->right);
        if (right==-1) { return -1; }
        
        if ( abs(left-right) > 1){
            return -1;
        }
        
        return 1 + max( left, right );
    }
};

int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(1);
    
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->left->left->left = new TreeNode(6);
    
    /*
     
       1
     /   \
    3     2
   / \
  4   5
 /
6
     
     */
    
    
    Solution solution;
    cout << solution.isBalanced(root) << endl;
    
    return 0;
}



