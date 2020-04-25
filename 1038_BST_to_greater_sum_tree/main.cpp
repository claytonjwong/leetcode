/*
 * 1038. Binary Search Tree to Greater Sum Tree
 *
 * Q: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
 * A: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/discuss/596866/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

using namespace std;

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        return go(root);
    }
private:
    TreeNode* go(TreeNode* root, int&& sum = 0) {
        if (root->right)
            go(root->right, move(sum));
        sum += root->val, root->val = sum;
        if (root->left)
            go(root->left, move(sum));
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
