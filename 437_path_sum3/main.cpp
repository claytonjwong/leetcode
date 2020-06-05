/*
 * 437. Path Sum III
 *
 * Q: https://leetcode.com/problems/path-sum-iii/
 * A: https://leetcode.com/problems/path-sum-iii/discuss/671026/Javascript-and-C%2B%2B-solutions
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
        int T;
        int dfs(TreeNode* root, int sum = 0) {
            return !root ? 0
                : int(sum + root->val == T) + dfs(root->left, sum + root->val) + dfs(root->right, sum + root->val);
        }
        int go(TreeNode* root) {
            return !root ? 0 : dfs(root) + go(root->left) + go(root->right);
        }
    public:
        int pathSum(TreeNode* root, int sum) {
            T = sum;
            return go(root);
        }
    };
}

namespace Verbose {
    class Solution {
        int T;
        int dfs(TreeNode* root, int sum = 0) {
            if (!root)
                return 0;
            sum += root->val;
            return int(sum == T) + dfs(root->left, sum) + dfs(root->right, sum);
        }
        int go(TreeNode* root) {
            if (!root)
                return 0;
            return dfs(root) + go(root->left) + go(root->right);
        }
    public:
        int pathSum(TreeNode* root, int sum) {
            T = sum;
            return go(root);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
