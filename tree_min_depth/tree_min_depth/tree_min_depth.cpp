/*
 
 111. Minimum Depth of Binary Tree
 
 https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 
 Given a binary tree, return the minimum depth
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 
 Example 1:
 
   1
 
 minDepth is 1 for a tree with a single node
 
 
 
 Example 2:
 
    1          0
   /          / \
  2          4   8
 
 minDepth is 2 for these trees
 
 */

#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution{
public:
    int minDepth(TreeNode* root){
        
        if (!root) { return -1; }
        return helper(root, 0);
    }
    
private:
    
    int helper(TreeNode* node, int depth){
        
        if (!node->left && !node->right){
            return depth;
        }
        
        int left = INT_MAX, right = INT_MAX;
        if (node->left) { left = helper(node->left, depth+1); }
        if (node->right) { right = helper(node->right, depth+1); }
        return min(left,right);
    }
};


int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(40);
    root->left->left = new TreeNode(3);
    
    Solution solution;
    cout << solution.minDepth(root) << endl;
    
    
    
    return 0;
}




