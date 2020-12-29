/*
 * 1457. Pseudo-Palindromic Paths in a Binary Tree
 *
 * Q: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
 * A: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/652445/Kt-Js-Py3-Cpp-Map
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    using Map = unordered_map<int, int>;
    using fun = function<void(TreeNode*)>;
    int pseudoPalindromicPaths (TreeNode* root, Map m = {}, int odd = 0, int paths = 0) {
        fun go = [&](auto root) {
            auto x = root->val;
            odd += ++m[x] & 1 ? 1 : -1;
            if (!root->left && !root->right)
                paths += odd <= 1;
            if (root->left)  go(root->left);
            if (root->right) go(root->right);
            odd += --m[x] & 1 ? 1 : -1;
        };
        go(root);
        return paths;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
