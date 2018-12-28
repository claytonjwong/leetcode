/*
 
 513. Find Bottom Left Tree Value
 
 https://leetcode.com/problems/find-bottom-left-tree-value/description/
 
 Given a binary tree, find the leftmost value in the last row of the tree.
 
 Example 1:
 Input:
 
  2
 / \
1   3
 
 Output:
 1
 Example 2:
 Input:
 
    1
   / \
  2   3
 /   / \
4   5   6
   /
  7
 
 Output:
 7
 Note: You may assume the tree (i.e., the given root node) is not NULL.
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>> depthList;
        depthList.push_back(vector<int>());
        depthList[0].push_back(root->val);
        
        //
        // fill in depthList using pre-order traversal of the tree,
        // so the bottom-leftmost node will be the last row, first column
        //
        helper(root, 0, depthList);
        
        return depthList[depthList.size()-1][0];
    }
    
    void helper(TreeNode* node, int depth, vector<vector<int>>& depthList){
        
        if (!node) { return; }
        while (depthList.size() == depth){
            depthList.push_back(vector<int>());
        }
        
        depthList[depth].push_back(node->val);
        
        helper(node->left, depth+1, depthList);
        helper(node->right, depth+1, depthList);
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    Solution solution;
    cout << solution.findBottomLeftValue(root) << endl;
    
    
    return 0;
}
