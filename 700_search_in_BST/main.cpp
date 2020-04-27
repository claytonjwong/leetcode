/*
 * 700. Search in a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/search-in-a-binary-search-tree/
 * A: https://leetcode.com/problems/search-in-a-binary-search-tree/discuss/600141/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int T) {
        while (root && root->val != T) {
            if (root->val > T)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
