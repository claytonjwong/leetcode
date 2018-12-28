/*

 236. Lowest Common Ancestor of a Binary Tree
 
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 
 _______3______
 /              \
 ___5__          ___1__
 /      \        /      \
 6      _2       0       8
 /  \
 7   4
 For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 
 */

#include <iostream>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) { return nullptr; }
        if (p==q){ return q; }
        return helper(root,p,q);
    }
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if (!root) { return nullptr; }
        if (root==p || root==q) { return root; }
        TreeNode* left=helper(root->left, p, q);
        TreeNode* right=helper(root->right, p, q);
        if (left && right) { return root; }
        return left ? left : right;
    }
};


int main(int argc, const char * argv[]) {
    
    TreeNode *root, *p, *q;
    
    root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    
    p=root->right;
    q=root->left->right;
    
    Solution solution;
    TreeNode* ancestor=solution.lowestCommonAncestor(root, p, q);
    
    
    return 0;
}









