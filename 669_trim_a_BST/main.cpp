/*
 * 669. Trim a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/trim-a-binary-search-tree/
 * A: https://leetcode.com/problems/trim-a-binary-search-tree/discuss/599189/Javascript-Python3-C%2B%2B-Recursive
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

namespace Concise {
    class Solution {
    public:
        using fun = function<void(TreeNode*)>;
        TreeNode* trimBST(TreeNode* root, int lo, int hi) {
            fun go = [&](auto root) {
                while (root->left  && root->left->val < lo)  root->left  = root->left->right ? root->left->right : nullptr;
                while (root->right && hi < root->right->val) root->right = root->right->left ? root->right->left : nullptr;
                if (root->left)  go(root->left);
                if (root->right) go(root->right);
            };
            go(root);
            while (root && root->val < lo) root = root->right;
            while (root && hi < root->val) root = root->left;
            return root;
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using fun = function<void(TreeNode*)>;
        TreeNode* trimBST(TreeNode* root, int lo, int hi) {
            fun go = [&](auto root) {
                if (root->left && root->left->val < lo) {
                    auto next = root->left->right;
                    while (next && next->val < lo)
                        next = next->right;
                    root->left = next;
                }
                if (root->right && hi < root->right->val) {
                    auto next = root->right->left;
                    while (next && hi < next->val)
                        next = next->left;
                    root->right = next;
                }
                if (root->left)  go(root->left);
                if (root->right) go(root->right);
            };
            go(root);
            while (root && root->val < lo) root = root->right;
            while (root && hi < root->val) root = root->left;
            return root;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
