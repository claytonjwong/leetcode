/*
 * 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 *
 * Q: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
 * A: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/discuss/537655/Javascript-and-C%2B%2B-solutions
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
    using TN = TreeNode*;
    TN getTargetCopy(TN a, TN b, TN c, TN ans = nullptr) {
        go(a, b, c, ans);
        return ans;
    }
private:
    void go(TN a, TN b, TN c, TN& ans) {
        if (a == c)
            ans = b;
        if (a->left)
            go(a->left, b->left, c, ans);
        if (a->right)
            go(a->right, b->right, c, ans);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
