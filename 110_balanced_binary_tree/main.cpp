/*
 * 110. Balanced Binary Tree
 *
 * Q: https://leetcode.com/problems/balanced-binary-tree/
 * A: https://leetcode.com/problems/balanced-binary-tree/discuss/981963/Kt-Js-Py3-Cpp-Post-Order-Traversal
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
    using fun = function<int(TreeNode*)>;
    bool isBalanced(TreeNode* root, bool ok = true) {
        fun go = [&](auto root) {
            if (!root)
                return 0;
            auto L = 1 + go(root->left),
                 R = 1 + go(root->right);
            if (1 < abs(L - R))
                ok = false;
            return max(L, R);
        };
        go(root);
        return ok;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
