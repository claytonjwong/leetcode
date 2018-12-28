/*
 
 669. Trim a Binary Search Tree
 
 https://leetcode.com/contest/leetcode-weekly-contest-48/problems/trim-a-binary-search-tree/
 
 Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.
 
 Example 1:
 Input:
 1
 / \
 0   2
 
 L = 1
 R = 2
 
 Output:
 1
 \
 2
 
 
 Example 2:
 Input:
 3
 / \
 0   4
 \
 2
 /
 1
 
 L = 1
 R = 3
 
 Output:
 3
 /
 2
 /
 1
 
 */

#include <iostream>
#include <queue>
#include <set>

using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL}{}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) { return NULL; }
        if (root->val > R) { return trimBST(root->left,  L, R); }
        if (root->val < L) { return trimBST(root->right, L, R); }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

int main(int argc, const char * argv[]) {
    /*
     TreeNode* root = new TreeNode(1);
     root->left = new TreeNode(0);
     root->right = new TreeNode(2);
     */
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(0);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(1);
    Solution solution;
    root = solution.trimBST(root, 1, 3);
    
    return 0;
}




