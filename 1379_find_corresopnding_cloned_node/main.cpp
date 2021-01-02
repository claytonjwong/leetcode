/*
 * 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * Q: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 * A: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/537655/Kt-Js-Py3-Cpp-Traverse-A%2BB-Simultaneously
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
    using fun = function<TreeNode*(TreeNode*, TreeNode*)>;
    TreeNode* getTargetCopy(TreeNode* A, TreeNode* B, TreeNode* T) {
        fun go = [&](auto a, auto b) {
            if (a == T)
                return b;
            auto L = a->left  ? go(a->left,  b->left)  : nullptr,
                 R = a->right ? go(a->right, b->right) : nullptr;
            return L ? L : R;
        };
        return go(A, B);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
