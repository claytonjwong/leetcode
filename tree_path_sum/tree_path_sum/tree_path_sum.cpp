/*
 
 112. Path Sum
 
 https://leetcode.com/problems/path-sum/description/
 
 
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        
        return helper(root, 0, sum);
    }
    
    bool helper(TreeNode* node, int curr_sum, int target){
        
        if (!node) { return false; }
        
        curr_sum += node->val;
        
        if (!node->left && !node->right){
            if (curr_sum == target) { return true; }
        }
        
        return helper(node->left, curr_sum, target) ||  helper(node->right, curr_sum, target);
    }
    

};

int main(int argc, const char * argv[]) {
   
    
    Solution solution;
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(-2);
    root->right->left = new TreeNode(1);
    cout << solution.hasPathSum(root, 0) << endl;
    
    return 0;
}



