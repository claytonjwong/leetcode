/*
 
 105. Construct Binary Tree from Preorder and Inorder Traversal
 
 https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 
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

class Solution{
public:
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        
        if (preorder.empty() || inorder.empty() || preorder.size() != inorder.size()){
            return NULL;
        }
        
        // take first element of the preorder and make it the root of the tree
        TreeNode* root = new TreeNode(preorder[0]);

        // use inorder to determine where to place this sub-tree's root (left/right)
        for (int i=1; i < preorder.size(); i++){
        
            TreeNode* parent = root;
            TreeNode* child = new TreeNode(preorder[i]);
            
            while (true){
                
                if ( isChildLeftOfParent(inorder, parent->val, child->val) ){
                    
                    if (!parent->left){
                        parent->left = child;
                        break;
                    } else {
                        parent = parent->left;
                    }
                }
                
                if ( isChildRightOfParent(inorder, parent->val, child->val) ){
                    
                    if (!parent->right){
                        parent->right = child;
                        break;
                    } else {
                        parent = parent->right;
                    }
                }
            }
        }
        
        return root;
    }
    
    bool isChildLeftOfParent(vector<int>& inorder, int parent_val, int child_val){
        
        // if parent is found first, the the child must be to the right, return false
        // otherwise if child is found first, then the child must be to the left, return true
        for (vector<int>::iterator itr=inorder.begin(); itr != inorder.end(); itr++){
            if (*itr == parent_val){
                return false;
            }
            if (*itr == child_val){
                return true;
            }
        }
        return false; // should never return here as long as parent_val and child_val exist in the array
    }
    
    bool isChildRightOfParent(vector<int>& inorder, int parent_val, int child_val){
        
        return !isChildLeftOfParent(inorder, parent_val, child_val);
    }

};


int main(int argc, const char * argv[]) {

    Solution solution;
    vector<int> preorder {3,9,20,15,7};
    vector<int> inorder {9,3,15,20,7};
    TreeNode* result = solution.buildTree(preorder,inorder);
    
    
    
    return 0;
}











