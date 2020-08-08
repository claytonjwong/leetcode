/*
 * 270. Closest Binary Search Tree Value
 *
 * Q2: https://leetcode.com/problems/closest-binary-search-tree-value
 * A2: https://leetcode.com/problems/closest-binary-search-tree-value/discuss/549446/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using fun = function<void(TreeNode*)>;
    int closestValue(TreeNode* root, double T, double best = numeric_limits<double>::max()) {
        fun go = [&](TreeNode* root) {
            if (!root)
                return;
            if (abs(root->val - T) < abs(best - T))
                best = root->val;
            go(root->left);
            go(root->right);
        };
        go(root);
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
