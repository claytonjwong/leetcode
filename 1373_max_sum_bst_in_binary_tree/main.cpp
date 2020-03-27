/*
 * 1373. Maximum Sum BST in Binary Tree
 *
 * Q: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
 * A: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/discuss/536727/Javascript-solution-(FAIL-test-case-53-of-55)
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
    int maxSumBST(TreeNode* root, int max = 0) {
        go(root, max);
        return max;
    }
private:
    using Tuple = tuple<int, int, int, int>;
    static constexpr auto INF = int(4 * 1e4) + 1;
    Tuple go(TreeNode* root, int& max, bool isBST = false, int sum = 0) {
        if (!root)
            return {INF, -INF, true, 0};
        auto [min_L, max_L, isBST_L, sum_L] = go(root->left, max);
        auto [min_R, max_R, isBST_R, sum_R] = go(root->right, max);
        if (isBST_L && isBST_R && max_L < root->val && root->val < min_R) {
            sum = root->val + sum_L + sum_R;
            max = std::max(max, sum);
            isBST = true;
        }
        auto minimum = std::min({min_L, min_R, root->val}),
             maximum = std::max({max_R, max_R, root->val});
        return {minimum, maximum, isBST, sum};
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->left->left = new TreeNode(6);
    root->left->left->left = new TreeNode(9);
    root->left->right = new TreeNode(1);
    root->left->right->left = new TreeNode(-5);
    root->left->right->left->right = new TreeNode(-3);
    root->left->right->right = new TreeNode(4);
    root->left->right->right->right = new TreeNode(10);
    cout << Solution().maxSumBST(root) << endl;
    return 0;
}
