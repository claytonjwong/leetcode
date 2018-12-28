/*
 
 110. Balanced Binary Tree
 
 https://leetcode.com/problems/balanced-binary-tree/description/
 
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 */

#include <iostream>
#include <unordered_map>
#include <vector>

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
        
        return depthCheck(root) != -1;
        
    }
    
    int depthCheck(TreeNode* node){
        
        if (!node) { return 0; }
        
        int leftDepth = depthCheck(node->left);
        if (leftDepth==-1){
            return -1;
        }
        
        int rightDepth = depthCheck(node->right);
        if (rightDepth==-1){
            return -1;
        }
        
        if (abs( leftDepth-rightDepth ) > 1 ){
            return -1;
        }
        return 1 + max( leftDepth, rightDepth );
        
    }

};

int main(int argc, const char * argv[]) {

    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution solution;
    
    cout << "0 == " << solution.isBalanced(root) << endl;
    
    return 0;
}







