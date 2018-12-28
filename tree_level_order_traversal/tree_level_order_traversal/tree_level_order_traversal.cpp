/*
 
 102. Binary Tree Level Order Traversal
 
 https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
  3
 / \
 9  20
   /  \
  15   7
 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]
 
 */


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int x) : val{x}, left{NULL}, right{NULL} {}
};


class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        
        levelOrderHelper(root, 0);
        
        return level;
    }
    
    void levelOrderHelper(TreeNode* node, int depth){
        
        // base case, node is NULL
        if (!node){
            return;
        }
        
        // pre-order traversal, append to vector at depth
        if (level.size() == depth){
            level.push_back(vector<int>());
        }
        
        level[depth].push_back(node->val);
        levelOrderHelper(node->left, depth+1);
        levelOrderHelper(node->right, depth+1);
    }
    
    
private:
    vector<vector<int>> level;
};


int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    
    Solution solution;
    
    vector<vector<int>> result = solution.levelOrder(root);
    
    
    
    return 0;
}










