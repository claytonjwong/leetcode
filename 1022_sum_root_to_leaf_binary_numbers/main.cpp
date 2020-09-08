/*
 * 1022. Sum of Root To Leaf Binary Numbers
 *
 * Q: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
 * A: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/discuss/275849/Javascript-Python3-C%2B%2B-recursive-solutions
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int sum = 0) {
        auto next = [=](auto sum) { return (sum << 1) | root->val; };
        if (!root) return 0;
        if (!root->left && !root->right) return next(sum);
        return sumRootToLeaf(root->left, next(sum)) + sumRootToLeaf(root->right, next(sum));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
