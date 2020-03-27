/*
 * 111. Minimum Depth of Binary Tree
 *
 * Q: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * A: https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/553010/Javascript-and-C%2B%2B-solutions
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
    int minDepth(TreeNode* root) {
        return root ? go(root) : 0;
    }
private:
    static constexpr auto INF = 1e9 + 7;
    int go(TreeNode* root, int depth = 1) {
        if (!root->left && !root->right)
            return depth;
        auto L = root->left  ? go(root->left,  depth + 1) : INF,
             R = root->right ? go(root->right, depth + 1) : INF;
        return min(L, R);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
