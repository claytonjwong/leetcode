/*
 
 687. Longest Univalue Path
 
 https://leetcode.com/contest/leetcode-weekly-contest-52/problems/longest-univalue-path/
 
 Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
 
 Note: The length of path between two nodes is represented by the number of edges between them.
 
 Example 1:
 
 Input:
 
 5
 / \
 4   5
 / \   \
 1   1   5
 Output:
 
 2
 Example 2:
 
 Input:
 
 1
 / \
 4   5
 / \   \
 4   4   5
 Output:
 
 2
 Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
 
 */

#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

using namespace std;

class Solution {
private:
    int helper(TreeNode*root, int &m){
        int l=(root->left) ? helper(root->left,m) : 0;
        int r=(root->right) ? helper(root->right,m) : 0;
        l=(root->left && root->val==root->left->val) ? l+1 : 0;
        r=(root->right && root->val==root->right->val) ? r+1 : 0;
        m=max(m,l+r);
        return max(l,r);
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int maxCnt=0;
        helper(root,maxCnt);
        return maxCnt;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(1);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(5);
    
    Solution solution;
    cout << solution.longestUnivaluePath(root) << endl;
    
    return 0;
}




