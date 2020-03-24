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
    int closestValue(TreeNode* root, double target, int ans = -1) {
        go(ans, root, target);
        return ans;
    }
private:
    void go(int& ans, TreeNode* root, double target, double best = numeric_limits<double>::max()) {
        auto diff = abs(target - root->val);
        if (best > diff)
            best = diff,
            ans = root->val;
        if (root->left) go(ans, root->left, target, best);
        if (root->right) go(ans, root->right, target, best);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
