/*
 
 
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};


class Solution {
public:
    
    bool isValidBST(TreeNode* root){
        
        if (!root) { return true; }
        
        vector<int> inorder;
        constructInorder(root, inorder);
        return ascendingOrder(inorder);
    }
    
    void constructInorder(TreeNode* node, vector<int>& inorder) {
        
        if (!node) { return; }
        
        constructInorder(node->left, inorder);
        inorder.push_back(node->val);
        constructInorder(node->right, inorder);
    }
    
    bool ascendingOrder(vector<int>& inorder){
        
        for (int i=0; i < inorder.size()-1; i++){
            if (inorder[i] >= inorder[i+1]){
                return false;
            }
        }
        return true;
    }

};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    TreeNode* tree = new TreeNode(-2147483648);
    
    
    cout << "1 == " << solution.isValidBST(tree) << endl;
    
    
    return 0;
}




