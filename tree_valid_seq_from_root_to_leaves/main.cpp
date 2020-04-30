/*
 * Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
 *
 * Q: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/
 * A: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/532/week-5/3315/discuss/604979/Javascript-and-C++-solutions
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
    bool isValidSequence(TreeNode* root, VI& A) {
        return go(root, A);
    }
private:
    bool go(TreeNode* root, VI& A, int i = 0) {
        int N = A.size();
        if (!root || root->val != A[i] || i > N - 1)
            return false;
        if (i == N - 1)
            return root->val == A[i] && !root->left && !root->right; // root..leaf path? 🎯
        return go(root->left, A, i + 1) || go(root->right, A, i + 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
