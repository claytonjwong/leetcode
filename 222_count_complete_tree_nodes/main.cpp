/*
 * 222. Count Complete Tree Nodes
 *
 * Q: https://leetcode.com/problems/count-complete-tree-nodes/
 * A: https://leetcode.com/problems/count-complete-tree-nodes/discuss/701940/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        return !root ? 0 : 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
