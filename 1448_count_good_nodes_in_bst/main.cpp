/*
 * 1448. Count Good Nodes in Binary Tree
 *
 * Q: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * A: https://leetcode.com/problems/count-good-nodes-in-binary-tree/discuss/639804/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    static constexpr int INF = 1e4 + 1;
    int goodNodes(TreeNode* root, int max = -INF) {
        return !root ? 0 : int(root->val >= max)
            + goodNodes(root->left, std::max(root->val, max))
            + goodNodes(root->right, std::max(root->val, max));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
