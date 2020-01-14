/*
 * 1315. Sum of Nodes with Even-Valued Grandparent
 *
 * Q: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
 * A: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/discuss/479681/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    TreeNode *left, *right;
    int val;
    TreeNode(int val) : left{nullptr}, right{nullptr}, val{val} {}
};

class Solution {
public:
    int sumEvenGrandparent(TreeNode* root, int sum = 0) {
        auto childSum = [=](auto node, int sum = 0) {
            if (root->val % 2 != 0)
                return 0;
            if (node->left) sum += node->left->val;
            if (node->right) sum += node->right->val;
            return sum;
        };
        if (root->left) sum += childSum(root->left) + sumEvenGrandparent(root->left);
        if (root->right) sum += childSum(root->right) + sumEvenGrandparent(root->right);
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
