/*
 * 404. Sum of Left Leaves
 *
 * Q: https://leetcode.com/problems/sum-of-left-leaves/
 * A: https://leetcode.com/problems/sum-of-left-leaves/discuss/809409/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

namespace OneLiner {
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root, bool left = false) {
            return !root ? 0 : !root->left && !root->right ? (left ? root->val : 0) : sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        int sumOfLeftLeaves(TreeNode* root, bool left = false) {
            if (!root)
                return 0;
            if (!root->left && !root->right)
                return left ? root->val : 0;
            return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
