/*
 * 1339. Maximum Product of Splitted Binary Tree
 *
 * Q: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
 * A: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/discuss/541816/Javascript-and-C%2B%2B-solutions
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
    using LL = long long;
    using VLL = vector<LL>;
    int maxProduct(TreeNode* root, VLL A = {}, LL max = 0) {
        auto total = go(A, root);
        for (auto i = 0; i + 1 < A.size(); ++i) // i + 1 to not process root at A[N - 1] (requires 2 cuts)
            max = std::max(max, A[i] * (total - A[i]));
        return max % int(1e9 + 7);
    }
private:
    LL go(VLL &A, TreeNode* root) {
        if (!root) return 0;
        A.push_back(go(A, root->left) + go(A, root->right) + root->val);
        return A.back();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
