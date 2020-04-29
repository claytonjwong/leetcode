/*
 * 124. Binary Tree Maximum Path Sum
 *
 * Q: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * A: https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603372/Javascript-and-C%2B%2B-solutions
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
    int maxPathSum(TreeNode* root) {
        auto max = root->val;
        go(root, max);
        return max;
    }
private:
    int go(TreeNode* root, int& max) {
        auto L = root->left ? go(root->left, max) : 0,
                R = root->right ? go(root->right, max) : 0;
        max = std::max({ max,
            root->val,
            root->val + L,
            root->val + R,
            root->val + L + R
        });
        return std::max({
            root->val,
            root->val + L,
            root->val + R
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
