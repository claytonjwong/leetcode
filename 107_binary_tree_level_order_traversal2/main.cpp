/*
 * 107. Binary Tree Level Order Traversal II
 *
 * Q: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * A: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/716311/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI ans;
    void go(TreeNode* root, int i = 0) {
        if (!root)
            return;
        if (i == ans.size())
            ans.push_back({});
        ans[i].push_back(root->val);
        go(root->left, i + 1);
        go(root->right, i + 1);
    }
public:
    VVI levelOrderBottom(TreeNode* root) {
        go(root);
        return { ans.rbegin(), ans.rend() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
