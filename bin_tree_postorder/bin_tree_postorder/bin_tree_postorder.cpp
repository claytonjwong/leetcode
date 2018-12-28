/*
 
 145. Binary Tree Postorder Traversal
 
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root, vector<int> ans={}) {
        if (root)
            go(root,ans);
        return ans;
    }
private:
    void go(TreeNode* node, vector<int>& ans){
        if (node->left) go(node->left,ans);
        if (node->right) go(node->right,ans);
        ans.push_back(node->val);
    }
};

int main(int argc, const char * argv[]) {
    
    
    return 0;
}
