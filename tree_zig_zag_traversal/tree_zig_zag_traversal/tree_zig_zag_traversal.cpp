/*
 
 103. Binary Tree Zigzag Level Order Traversal
 
 https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 
 
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
  3
 / \
 9  20
   /  \
  15   7
 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
 
 
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        
        vector<vector<int>> result;
        
        fillPreorder(root, 0);

        for (int depth=0; depth < preorder.size(); depth++){
            
            vector<int> depth_list = preorder[depth];
            
            if (depth % 2){
                reverse(depth_list.begin(), depth_list.end());
            }
            
            result.push_back(depth_list);
        }
        
        return result;
    }
    
    
    void fillPreorder(TreeNode* node, int depth){
        
        if (!node){ return; }
        
        if (preorder.size() == depth){
            preorder.push_back(vector<int>());
        }
        preorder[depth].push_back(node->val);
        fillPreorder(node->left, depth+1);
        fillPreorder(node->right, depth+1);
    }
    

    
    
private:
    vector<vector<int>> preorder;
};



int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    Solution solution;
    vector<vector<int>> result = solution.zigzagLevelOrder(root);
    
    
    return 0;
}










