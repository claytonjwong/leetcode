/*
 * 1457. Pseudo-Palindromic Paths in a Binary Tree
 *
 * Q: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
 * A: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/discuss/652445/Javascript-and-C%2B%2B-solutions
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
    int pseudoPalindromicPaths (TreeNode* root, int ans = 0) {
        go(ans, root);
        return ans;
    }
private:
    using Map = unordered_map<int, int>;
    void go(int& ans, TreeNode* root, Map&& m = {}, int odd = 0) {
        odd += ++m[root->val] % 2 ? 1 : -1;
        if (!root->left && !root->right)
            ans += int(odd <= 1);
        if (root->left) go(ans, root->left, move(m), odd);
        if (root->right) go(ans, root->right, move(m), odd);
        odd += --m[root->val] % 2 ? 1 : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
