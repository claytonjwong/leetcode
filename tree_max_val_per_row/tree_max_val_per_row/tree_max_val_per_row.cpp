/*
 
 515. Find Largest Value in Each Tree Row
 
 https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 
 You need to find the largest value in each row of a binary tree.
 
 Example:
 Input:
 
    1
   / \
  3   2
 / \   \
5   3   9
 
 Output: [1, 3, 9]
 
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        
        helper(root, 0, res);
        
        return res;
    }

private:
    void helper(TreeNode* node, int depth, vector<int>& maxVals){
        
        if (!node) { return; }
        
        if ( depth == maxVals.size() ){
            maxVals.push_back(node->val);
        }
        
        maxVals[depth] = max( maxVals[depth], node->val);
        
        helper(node->left, depth+1, maxVals);
        helper(node->right, depth+1, maxVals);
    }

};



int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    
    Solution solution;
    vector<int> result = solution.largestValues(root);
    
    for (auto el : result ){
        cout << el << ", ";
    }
    cout << endl;
    
    return 0;
}




