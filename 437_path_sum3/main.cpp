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

class Solution {
public:
    using fun = function<int(TreeNode*, int)>;
    int pathSum(TreeNode* root, int T) {
        fun go = [&](TreeNode* root, int sum = 0) {
            if (!root)
                return 0;
            sum += root->val;
            return int(sum == T) + go(root->left, sum) + go(root->right, sum);
        };
        fun traverse = [&](TreeNode* root, int _ = 0) {
            if (!root)
                return 0;
            return go(root, _) + traverse(root->left, _) + traverse(root->right, _);
        };
        return traverse(root, 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
