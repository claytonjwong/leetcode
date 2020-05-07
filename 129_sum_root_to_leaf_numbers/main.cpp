/*
 * 129. Sum Root to Leaf Numbers
 *
 * Q: https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * A: https://leetcode.com/problems/sum-root-to-leaf-numbers/discuss/41378/simple-c-using-recursion/530599
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return root ? go(root) : 0;
    }
private:
    int go(TreeNode* root, int pre = 0) {
        auto cur = pre * 10 + root->val;
        if (!root->left && !root->right)
            return cur;
        auto L = root->left  ? go(root->left,  cur) : 0,
             R = root->right ? go(root->right, cur) : 0;
        return L + R;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
