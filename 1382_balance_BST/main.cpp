/*
 * 1382. Balance a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/balance-a-binary-search-tree/
 * A: https://leetcode.com/problems/balance-a-binary-search-tree/discuss/540272/Javascript-and-C%2B%2B-solutions
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
    using TN = TreeNode*;
    TN balanceBST(TN root, VI A = {}) {
        go(A, root);
        return bal(A, 0, A.size() - 1);
    }
private:
    void go(VI& A, TN root) {
        if (root->left) go(A, root->left);
        A.push_back(root->val);
        if (root->right) go(A, root->right);
    }
    TN bal(VI& A, int i, int j) {
        auto k = (i + j) / 2;
        auto root = new TreeNode(A[k]);
        root->left  = i < k ? bal(A, i, k - 1) : nullptr;
        root->right = k < j ? bal(A, k + 1, j) : nullptr;
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
