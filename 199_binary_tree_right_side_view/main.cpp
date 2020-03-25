/*
 * 199. Binary Tree Right Side View
 *
 * Q: https://leetcode.com/problems/binary-tree-right-side-view/
 * A: https://leetcode.com/problems/binary-tree-right-side-view/discuss/56023/Simple-C%2B%2B-using-depth-list
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
    using VVI = vector<VI>;
    VI rightSideView(TreeNode* root, VVI D = {}, VI ans = {}) {
        go(D, root);
        transform(D.begin(), D.end(), back_inserter(ans), [](auto& row) { return row.back(); });
        return ans;
    }
private:
    void go(VVI& D, TreeNode* root, int depth = 0) {
        if (!root)
            return;
        if (D.size() == depth)
            D.push_back({});
        D[depth].push_back(root->val);
        go(D, root->left, depth + 1);
        go(D, root->right, depth + 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
