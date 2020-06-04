/*
 * 872. Leaf-Similar Trees
 *
 * Q: https://leetcode.com/problems/leaf-similar-trees/
 * A: https://leetcode.com/problems/leaf-similar-trees/discuss/152310/Concise-C%2B%2B-recursive-solution
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    using VI = vector<int>;
    struct {
        VI A, B;
    } leaves;
    bool leafSimilar(TreeNode* A, TreeNode* B) {
        go(A, leaves.A);
        go(B, leaves.B);
        return leaves.A == leaves.B;
    }

    void go(TreeNode* node, VI& leaves) {
        if (!node)
            return;
        if (!node->left && !node->right)
            leaves.push_back(node->val);
        go(node->left, leaves);
        go(node->right, leaves);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
