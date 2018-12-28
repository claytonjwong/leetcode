/*
 
 199. Binary Tree Right Side View
 
 https://leetcode.com/problems/binary-tree-right-side-view/description/
 
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 For example:
 Given the following binary tree,
    1            <---
  /   \
 2     3         <---
  \     \
   5     4       <---
 You should return [1, 3, 4].
 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        vector<vector<int>> nodeListPerDepth;
        depthList(root, nodeListPerDepth, 0);
        
        for (auto nodeList : nodeListPerDepth){
            result.push_back(*(nodeList.end()-1));
        }
        
        
        return result;
        
    }
    
    void depthList(TreeNode* node, vector<vector<int>>& list, int depth){
        
        if (!node) { return; }
        
        if (list.size() == depth){
            list.push_back(vector<int>());
        }
        list[depth].push_back(node->val);
        depthList(node->left, list, depth+1);
        depthList(node->right, list, depth+1);
    }
};



int main(int argc, const char * argv[]) {

    /*
     
     Given the following binary tree,
        1            <---
      /   \
     2     3         <---
      \     \
       5     4       <---
     You should return [1, 3, 4].
     
     */
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(69);
    root->right->right = new TreeNode(4);
    
    Solution solution;
    
    vector<int> result = solution.rightSideView(root);
    
    
    return 0;
}












