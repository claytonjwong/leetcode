/*
 
 366. Find Leaves of Binary Tree
 
 https://leetcode.com/problems/find-leaves-of-binary-tree/description/
 
 Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
 
 Example:
 Given binary tree
    1
   / \
  2   3
 / \
4   5
 Returns [4, 5, 3], [2], [1].
 
 Explanation:
 1. Removing the leaves [4, 5, 3] would result in this tree:
 
   1
  /
 2
 
 2. Now removing the leaf [2] would result in this tree:
 
 1
 
 3. Now removing the leaf [1] would result in the empty tree:
 
 []
 Returns [4, 5, 3], [2], [1].
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        vector<vector<int>> res;
        if (!root) { return res; }
        
        unordered_map<TreeNode*,bool> removed;
        while(removed.find(root) == removed.end()){
            
            //
            // current set of leaves for this iteration through the tree
            //
            vector<int> leaves;
            
            //
            // dfs
            //
            vector<TreeNode*> stack;
            stack.push_back(root);
            while (!stack.empty()){
                TreeNode* curr = stack.back();
                stack.pop_back();
                
                //
                // check for real leaf node, or new leaf node due to prevoius removals
                //
                bool left = true;
                bool right = true;
                
                if ( !curr->left || removed.find(curr->left) != removed.end() ){
                    left = false;
                }
                if ( !curr->right || removed.find(curr->right) != removed.end() ){
                    right = false;
                }
                
                if ( !left && !right ) {
                    
                    leaves.push_back(curr->val);
                    removed[curr]=true;
                }
            
                //
                // iterate through the rest of the tree
                // by adding non-NULL and non-removed nodes onto the stack
                //
                if (left)  { stack.push_back(curr->left);  }
                if (right) { stack.push_back(curr->right); }
            }
            
            //
            // add current set of leaves onto the end-result
            //
            res.push_back(leaves);
        }
    
        return res;
    }
};



int main(int argc, const char * argv[]) {

    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    
    
    Solution solution;
    vector<vector<int>> result = solution.findLeaves(root);
    
    for ( auto v : result){
        cout << "[";
        for ( auto n : v ){
            cout << n << ",";
        }
        cout << "], " << endl;
    }
    
    
    return 0;
}




