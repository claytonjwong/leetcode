/*
 * 543. Diameter of Binary Tree
 *
 * Q: https://leetcode.com/problems/diameter-of-binary-tree/
 * A: https://leetcode.com/problems/diameter-of-binary-tree/discuss/115019/Simple-C%2B%2B-Recursive-Solution
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root, int max = 0) {
        if (root)
            go(root, max);
        return max;
    }
private:
    int go(TreeNode* root, int& max) {
        auto L = root->left  ? 1 + go(root->left, max)  : 0,
             R = root->right ? 1 + go(root->right, max) : 0;
        max = std::max(max, L + R);
        return std::max(L, R);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
