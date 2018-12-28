/*
 
 222. Count Complete Tree Nodes
 
 https://leetcode.com/problems/count-complete-tree-nodes/description/
 
 Given a complete binary tree, count the number of nodes.
 
 Definition of a complete binary tree from Wikipedia:
 In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 
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
    int countNodes(TreeNode* root) {
        return go(root);
    }
private:
    int go(TreeNode* node){
        if (!node) return 0;
        int l=0,r=0;
        auto itl=node,itr=node;
        while (itl){ ++l; itl=itl->left; }
        while (itr){ ++r; itr=itr->right; }
        return l==r ? (1<<l)-1 : 1+go(node->left)+go(node->right);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    
    cout << s.countNodes(root) << endl;
    
    return 0;
}




