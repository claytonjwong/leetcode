/*
 
 124. Binary Tree Maximum Path Sum
 
 https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 
 Given a binary tree, find the maximum path sum.
 
 For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 
 For example:
 Given the below binary tree,
 
 1
 / \
 2   3
 Return 6.
 
 */

#include <iostream>
#include <limits>

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

using namespace std;

class Solution {
private:
    int helper(TreeNode* root, int &m){
        int l=(root->left) ? helper(root->left,m) : 0;
        int r=(root->right) ? helper(root->right,m) : 0;
        int curr=root->val;
        if (l>0) curr+=l;
        if (r>0) curr+=r;
        m=max(m,curr);
        if (l<=0 && r<=0) return root->val;
        return max(root->val+l, root->val+r);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int maxSum=INT_MIN;
        helper(root,maxSum);
        return maxSum;
    }
};

int main(int argc, const char * argv[]) {
    
    
    TreeNode* root=new TreeNode(2);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right=new TreeNode(3);

    Solution solution;
    cout << solution.maxPathSum(root) << endl;
    
    return 0;
}




