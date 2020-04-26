/*
 * 669. Trim a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/trim-a-binary-search-tree/
 * A: https://leetcode.com/problems/trim-a-binary-search-tree/discuss/599189/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root)
            return root;
        go(root, L, R);
        while (root && root->val < L) root = root->right;
        while (root && root->val > R) root = root->left;
        return root;
    }
private:
    void go(TreeNode* root, int L, int R) {
        while (root->left  && root->left->val  < L) root->left = root->left->right ? root->left->right : nullptr;
        while (root->right && root->right->val > R) root->right = root->right->left ? root->right->left : nullptr;
        if (root->left)  go(root->left,  L, R);
        if (root->right) go(root->right, L, R);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
