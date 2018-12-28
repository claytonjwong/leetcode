/*
 
 662. Maximum Width of Binary Tree
 
 https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 
 Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.
 
 The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.
 
 Example 1:
 Input:
 
 1
 /   \
 3     2
 / \     \
 5   3     9
 
 Output: 4
 Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
 Example 2:
 Input:
 
 1
 /
 3
 / \
 5   3
 
 Output: 2
 Explanation: The maximum width existing in the third level with the length 2 (5,3).
 Example 3:
 Input:
 
 1
 / \
 3   2
 /
 5
 
 Output: 2
 Explanation: The maximum width existing in the second level with the length 2 (3,2).
 Example 4:
 Input:
 
 1
 / \
 3   2
 /     \
 5       9
 /         \
 6           7
 Output: 8
 Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).
 
 
 Note: Answer will in the range of 32-bit signed integer.
 
 
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
    int widthOfBinaryTree(TreeNode* root){
        
        if (!root) { return 0; }
        
        
        maxWidth = 0;
        helper(root, 1, 0);
        return maxWidth;
    }

private:
    vector<int> leftMostNodePerDepth;
    int maxWidth;
    
    void helper(TreeNode* root, int nodePosition, int depth){
        
        if (!root) { return; }
        
        if (leftMostNodePerDepth.size() == depth){
            leftMostNodePerDepth.push_back(nodePosition);
        }
        
        maxWidth = max( maxWidth, abs(leftMostNodePerDepth[depth] - nodePosition) + 1);
        
        helper(root->left,  (2 * nodePosition),     depth + 1);
        helper(root->right, (2 * nodePosition) + 1, depth + 1);
    }
    
};


int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->right->right->right = new TreeNode(15);
    
    
    Solution solution;
    cout << solution.widthOfBinaryTree(root) << endl;
    
    
    return 0;
}




