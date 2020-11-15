/*
 * 938. Range Sum of BST
 *
 * Q: https://leetcode.com/problems/range-sum-of-bst/
 * A: https://leetcode.com/problems/range-sum-of-bst/discuss/192070/Kt-Js-Py3-Cpp-solutions
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
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        if (!root)
            return 0;
        auto x = lo <= root->val && root->val <= hi ? root->val : 0;
        return x + rangeSumBST(root->left, lo, hi) + rangeSumBST(root->right, lo, hi);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
