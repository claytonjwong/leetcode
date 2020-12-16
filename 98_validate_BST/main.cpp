/*
 * 98. Validate Binary Search Tree
 *
 * Q: https://leetcode.com/problems/validate-binary-search-tree/
 * A: https://leetcode.com/problems/validate-binary-search-tree/discuss/116826/Kt-Js-Py3-Cpp-Recursive
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root, long lo = -(6e9), long hi = 6e9) {
        if (!root)
            return true;
        if (root->val <= lo || hi <= root->val)
            return false;
        return isValidBST(root->left, lo, root->val) && isValidBST(root->right, root->val, hi);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
