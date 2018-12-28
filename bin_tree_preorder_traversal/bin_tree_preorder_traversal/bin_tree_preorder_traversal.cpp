/*
 
 144. Binary Tree Preorder Traversal
 
 Q: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 A: https://leetcode.com/problems/binary-tree-preorder-traversal/discuss/142910/Straightforward-C++-recursive-solution
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root, vector<int> ans={}) {
        if (root)
            go(root,ans);
        return ans;
    }
private:
    void go(TreeNode* node, vector<int>& ans){
        ans.push_back(node->val);
        if (node->left) go(node->left,ans);
        if (node->right) go(node->right,ans);
    }
};

int main(int argc, const char * argv[]) {
    
    
    
    
    return 0;
}


