/*
 
 94. Binary Tree Inorder Traversal
 
 https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 
 Given a binary tree, return the inorder traversal of its nodes' values.
 
 For example:
 Given binary tree [1,null,2,3],
 1
 \
 2
 /
 3
 return [1,3,2].
 
 Note: Recursive solution is trivial, could you do it iteratively?
 
 */


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) { return res; }
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        while (curr || !s.empty()){
            
            while (curr){
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top(); s.pop();
            res.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return res;
    }
    
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
    
private:
    void traverse(TreeNode* node, vector<int>& path){
        if (!node) { return; }
        
        if (node->left) { traverse(node->left, path); }
        path.push_back(node->val);
        if (node->right) { traverse(node->right, path); }
    }
};



int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    Solution solution;
    vector<int> result = solution.inorderTraversal(root);
    for (auto el : result){
        cout << el << ",";
    }
    cout << endl;

    result = solution.inorderTraversal2(root);
    for (auto el : result){
        cout << el << ",";
    }
    cout << endl;

    
    return 0;
}





