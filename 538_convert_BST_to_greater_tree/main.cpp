/*
 * 538. Convert BST to Greater Tree
 *
 * Q: https://leetcode.com/problems/convert-bst-to-greater-tree/
 * A: https://leetcode.com/problems/convert-bst-to-greater-tree/discuss/596870/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

using namespace std;

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        return go(root);
    }
private:
    TreeNode* go(TreeNode* root, int&& sum = 0) {
        if (root->right)
            go(root->right, move(sum));
        sum += root->val, root->val = sum;
        if (root->left)
            go(root->left, move(sum));
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
