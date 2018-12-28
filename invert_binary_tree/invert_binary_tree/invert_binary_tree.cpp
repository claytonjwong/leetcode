/*

 226. Invert Binary Tree
 
 https://leetcode.com/problems/invert-binary-tree/description/
 
 Invert a binary tree.
      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 
 to
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
 
 Trivia:
 This problem was inspired by this original tweet by Max Howell:
 Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
 
 */


#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        return go(root);
    }
private:
    TreeNode* go(TreeNode* node){
        swap(node->left, node->right);
        if (node->left) go(node->left);
        if (node->right) go(node->right);
        return node;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    auto res=s.invertTree(root);
    
    
    return 0;
}



