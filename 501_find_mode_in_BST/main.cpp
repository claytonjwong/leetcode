/*
 * 501. Find Mode in Binary Search Tree
 *
 * Q: https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * A: https://leetcode.com/problems/find-mode-in-binary-search-tree/discuss/595358/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    VI findMode(TreeNode* root, Map m = {}, int max = 0, VI ans = {}) {
        go(root, m, max);
        for (auto [val, cnt]: m)
            if (cnt == max)
                ans.push_back(val);
        return ans;
    }
private:
    void go(TreeNode* root, Map& m, int& max) {
        if (!root)
            return;
        ++m[root->val];
        max = std::max(max, m[root->val]);
        go(root->left, m, max);
        go(root->right, m, max);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
