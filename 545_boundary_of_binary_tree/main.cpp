/*
 * 545. Boundary of Binary Tree
 *
 * Q: https://leetcode.com/problems/boundary-of-binary-tree/
 * A: https://leetcode.com/problems/boundary-of-binary-tree/discuss/583973/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using VI = vector<int>;
    VI ans;
    VI boundaryOfBinaryTree(TreeNode* root) {
        if (!root)
            return ans;
        ans.push_back(root->val);
        if (root->left)
            goLeft(root->left),
            goLeaf(root->left);
        if (root->right)
            goLeaf(root->right),
            goRight(root->right);
        return ans;
    }
private:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    void goLeft(TreeNode* root) {
        if (isLeaf(root))
            return;
        ans.push_back(root->val); // push in forward order
        if (root->left) goLeft(root->left);
        else
        if (root->right) goLeft(root->right);
    }
    void goRight(TreeNode* root) {
        if (isLeaf(root))
            return;
        if (root->right) goRight(root->right);
        else
        if (root->left) goRight(root->left);
        ans.push_back(root->val); // push in reverse order
    }
    void goLeaf(TreeNode* root) {
        if (isLeaf(root))
            ans.push_back(root->val);
        if (root->left)  goLeaf(root->left);
        if (root->right) goLeaf(root->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
