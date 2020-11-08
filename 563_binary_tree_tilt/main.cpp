/*
 * 563. Binary Tree Tilt
 *
 * Q: https://leetcode.com/problems/binary-tree-tilt/
 * A: https://leetcode.com/problems/binary-tree-tilt/discuss/928266/Kt-Js-Py3-Cpp-Post-Order-Traversal
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
    int findTilt(TreeNode* root, int total = 0) {
        fun go = [&](auto root) {
            if (!root)
                return 0;
            auto L = go(root->left),
                 R = go(root->right);
            total += abs(L - R);
            return root->val + L + R;
        };
        go(root);
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
