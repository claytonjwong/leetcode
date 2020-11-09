/*
 * 1026. Maximum Difference Between Node and Ancestor
 *
 * Q: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
 * A: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/discuss/390492/Kt-Js-Py3-Cpp-Pre-Order-Traversal
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
    using fun = function<int(TreeNode*, int, int)>;
    int maxAncestorDiff(TreeNode* root, int best = 0) {
        fun go = [&](auto root, auto lo, auto hi) {
            if (!root)
                return abs(lo - hi);
            lo = min(lo, root->val);
            hi = max(hi, root->val);
            return max(go(root->left, lo, hi), go(root->right, lo, hi));
        };
        return go(root, root->val, root->val);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
