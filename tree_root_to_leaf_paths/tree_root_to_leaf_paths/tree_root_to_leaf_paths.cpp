/*
 
 257. Binary Tree Paths
 
 https://leetcode.com/problems/binary-tree-paths/description/
 
 Given a binary tree, return all root-to-leaf paths.
 
 For example, given the following binary tree:
 
    1
  /   \
 2     3
  \
   5
 
 All root-to-leaf paths are:
 
 ["1->2->5", "1->3"]
 
 
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

class Solution{
public:
    
    vector<string> binaryTreePaths(TreeNode* root){
        
        treePaths.clear();
        
        if (!root) { return treePaths; }
        
        helper(root, to_string(root->val));
        
        return treePaths;;
    }


    void helper(TreeNode* node, string path){

        if (!node) { return; }
        
        if (node->left){
            helper(node->left, path + "->" + to_string(node->left->val));
        }
        if (node->right){
            helper(node->right, path + "->" + to_string(node->right->val));
        }
        
        if (!node->left && !node->right){
            treePaths.push_back(path);
        }
        
    }
    
    
private:
    
    vector<string> treePaths;
    
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(2);
    
    vector<string> result = solution.binaryTreePaths(root);
    
    cout << "Paths:" << endl;
    
    for (auto path : result){
        cout << path << endl;
    }
    
    return 0;
}















