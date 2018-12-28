/*
 
 235. Lowest Common Ancestor of a Binary Search Tree
 
 https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 
 Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 
 According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
 
 _______6______
 /              \
 ___2__          ___8__
 /      \        /      \
 0      _4       7       9
 /  \
 3   5
 For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
 
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return go(root,p,q);
    }
private:
    TreeNode* go(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root==p || root==q) return root;
        auto left=(root->left) ? go(root->left,p,q) : nullptr;
        auto right=(root->right) ? go(root->right,p,q) : nullptr;
        return (left && right) ? root : (left) ? left : right;
    }
};

/*
shared_ptr<TreeNode<T>> FirstCommonAncestor(
                                            shared_ptr<TreeNode<T>> root,
                                            shared_ptr<TreeNode<T>> p,
                                            shared_ptr<TreeNode<T>> q){
    if (!root || !p || !q) { return nullptr; }
    return FirstCommonAncestorHelper(root, p, q);
}

shared_ptr<TreeNode<T>> FirstCommonAncestorHelper(
                                                  shared_ptr<TreeNode<T>> root,
                                                  shared_ptr<TreeNode<T>> p,
                                                  shared_ptr<TreeNode<T>> q){
    if (!root) { return nullptr; }
    if (root.get()==p.get() || root.get()==q.get()) { return root; }
    auto left=FirstCommonAncestorHelper(root->left, p, q);
    auto right=FirstCommonAncestorHelper(root->right, p, q);
    if (left && right){ return root; }
    return left!=nullptr ? left : right;
}
*/
 
int main(int argc, const char * argv[]) {
    
    Solution s;
    
    TreeNode* root=new TreeNode(6);
    root->left=new TreeNode(2);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(0);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(3);
    root->left->right->right=new TreeNode(5);
    
    TreeNode* p=root->left;
    TreeNode* q=root->left->right;
    auto res=s.lowestCommonAncestor(root, p, q);
    
    
    return 0;
}



