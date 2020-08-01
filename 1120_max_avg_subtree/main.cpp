/*
 * 1120. Maximum Average Subtree
 *
 * Q: https://leetcode.com/problems/maximum-average-subtree/
 * A: https://leetcode.com/problems/maximum-average-subtree/discuss/765869/Javascript-Python3-C%2B%2B-post-order-traversal
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    using Pair = pair<int, int>;
    using fun = function<Pair(TreeNode*)>;
    double maximumAverageSubtree(TreeNode* root, double max = 0) {
        fun go = [&](TreeNode* root) -> Pair {
            if (!root)
                return {0, 0};
            auto [L, M] = go(root->left);
            auto [R, N] = go(root->right);
            double sum = root->val + L + R,
                   cnt = 1 + M + N;  // +1 for root node
            max = std::max(max, sum / cnt);
            return {sum, cnt};
        };
        go(root);
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
