/*
 * 701. Insert into a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * A: https://leetcode.com/problems/insert-into-a-binary-search-tree/discuss/881995/Javascript-Python3-C%2B%2B-Recursive
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
    using fun = function<TreeNode*(TreeNode*, int)>;
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        fun go = [&](auto root, auto x) {
            if (x < root->val) {
                if (root->left)
                    go(root->left, x);
                else
                    root->left = new TreeNode(x);
            } else {
                if (root->right)
                    go(root->right, x);
                else
                    root->right = new TreeNode(x);
            }
            return root;
        };
        return root ? go(root, x) : new TreeNode(x);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
