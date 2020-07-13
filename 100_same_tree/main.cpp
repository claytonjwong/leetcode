/*
 * 100. Same Tree
 *
 * Q: https://leetcode.com/problems/same-tree/
 * A: https://leetcode.com/problems/same-tree/discuss/734300/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

namespace Concise {
    class Solution {
    public:
        bool isSameTree(TreeNode* a, TreeNode* b) {
            return !a && !b ? true : !a || !b || a->val != b->val ? false : isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        bool isSameTree(TreeNode* a, TreeNode* b) {
            if (!a && !b)                     // 🛑 base case: null nodes ✅
                return true;
            if (!a || !b || a->val != b->val) // 🛑 base case: nodes differ ❌
                return false;
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
