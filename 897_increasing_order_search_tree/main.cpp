/*
 * 897. Increasing Order Search Tree
 *
 * Q: https://leetcode.com/problems/increasing-order-search-tree/
 * A: https://leetcode.com/problems/increasing-order-search-tree/discuss/165898/Kt-Js-Py3-Cpp-solutions
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
    using VT = vector<TreeNode*>;
    using fun = function<void(TreeNode*)>;
    TreeNode* increasingBST(TreeNode* root, VT A = {}) {
        fun go = [&](auto root) {
            if (!root)
                return;
            go(root->left);
            A.push_back(root);
            go(root->right);
            root->left = root->right = nullptr;
        };
        go(root);
        auto sentinel = new TreeNode(-1),
             cur = sentinel;
        for (auto root: A)
            cur = cur->right = root;
        return sentinel->right;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
