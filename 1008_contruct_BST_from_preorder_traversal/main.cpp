/*
 * 1008. Construct Binary Search Tree from Preorder Traversal
 *
 * Q: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * A: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/discuss/252236/Concise-C%2B%2B
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using VI = vector<int>;
    TreeNode* bstFromPreorder(VI& A) {
        auto root = new TreeNode(A[0]);
        for (auto i{ 1 }; i < A.size(); ++i)
            add(root, A[i]);
        return root;
    }
private:
    void add(TreeNode* root, int val) {
        if (root->val > val) {
            if (!root->left) {
                root->left = new TreeNode(val);
                return;
            }
            add(root->left, val);
        } else {
            if (!root->right) {
                root->right = new TreeNode(val);
                return;
            }
            add(root->right, val);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
