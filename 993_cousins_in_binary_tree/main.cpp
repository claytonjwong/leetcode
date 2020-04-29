/*
 * 993. Cousins in Binary Tree
 *
 * Q: https://leetcode.com/problems/cousins-in-binary-tree/
 * A: https://leetcode.com/problems/cousins-in-binary-tree/discuss/602323/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using Map = unordered_map<int, int>;
    bool isCousins(TreeNode* root, int x, int y, int depth = 1, Map P = {}, Map D = {}) {
        queue<TreeNode*> q{{ root }};
        while (!q.empty()) {
            auto K = q.size();
            while (K--) {
                auto p = q.front(); q.pop(); // parent
                if (p->left) {
                    if (p->left->val == x) P[x] = p->val, D[x] = depth;
                    if (p->left->val == y) P[y] = p->val, D[y] = depth;
                    q.push(p->left);
                }
                if (p->right) {
                    if (p->right->val == x) P[x] = p->val, D[x] = depth;
                    if (p->right->val == y) P[y] = p->val, D[y] = depth;
                    q.push(p->right);
                }
            }
            ++depth;
        }
        return P[x] != P[y] && D[x] == D[y]; // diff parent and same depth 🎯
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
