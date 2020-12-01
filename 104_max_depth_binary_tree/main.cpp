/*
 * 104. Maximum Depth of Binary Tree
 *
 * Q: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * A: https://leetcode.com/problems/maximum-depth-of-binary-tree/discuss/955868/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return !root ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
