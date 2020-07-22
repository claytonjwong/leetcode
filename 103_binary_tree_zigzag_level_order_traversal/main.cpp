/*
 * 103. Binary Tree Zigzag Level Order Traversal
 *
 * Q: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * A: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/749264/Javascript-Python3-C%2B%2B-BFS-per-Level
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Queue = deque<TreeNode*>;
    VVI zigzagLevelOrder(TreeNode* root, int rev = 0, VVI ans = {}) {
        if (!root)
            return ans;
        Queue q{ 1, root };
        while (q.size()) {
            ans.push_back({});
            transform(q.begin(), q.end(), back_inserter(ans.back()), [](auto node) {
                return node->val;
            });
            if (rev)
                reverse(ans.back().begin(), ans.back().end());
            int k = q.size();
            while (k--) {
                auto cur = q.front(); q.pop_front();
                if (cur->left)  q.push_back(cur->left);
                if (cur->right) q.push_back(cur->right);
            }
            rev ^= 1;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
