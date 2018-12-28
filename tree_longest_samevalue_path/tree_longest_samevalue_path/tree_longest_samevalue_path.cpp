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
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int longestPath=0;
        helper(root, longestPath);
        return longestPath;
    }
private:
    int helper(TreeNode* root, int& m){
        int l=root->left ? helper(root->left, m) : 0;
        int r=root->right ? helper(root->right, m) : 0;
        l=(root->left && root->left->val==root->val) ? l+1 : 0;
        r=(root->right && root->right->val==root->val) ? r+1 : 0;
        m=max(m,l+r);
        return max(l,r);
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(4);
    root->left=new TreeNode(4);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(4);
    
    Solution solution;
    cout << solution.longestUnivaluePath(root) << endl;
    
    
    return 0;
}





