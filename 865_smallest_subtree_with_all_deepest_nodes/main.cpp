/*
 * 865. Smallest Subtree with all the Deepest Nodes
 *
 * Q: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
 * A: https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/discuss/614972/Javascript-and-C%2B%2B-solutions
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root, TreeNode* ans = nullptr) {
        go(ans, root);
        return ans;
    }
private:
    int go(TreeNode*& ans, TreeNode* root, int&& max = 0, int i = 0) {
        if (!root->left && !root->right)
            max = std::max(max, i);
        auto L = root->left  ? go(ans, root->left,  move(max), i + 1) : i,
             R = root->right ? go(ans, root->right, move(max), i + 1) : i;
        if (L == max && R == max)
            ans = root;
        return std::max(L, R);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
