/*
 * 111. Minimum Depth of Binary Tree
 *
 * Q: https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * A: https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/553010/Kt-Js-Py3-Cpp-DFS-%2B-BFS
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

namespace DFS {
    class Solution {
    public:
        using fun = function<int(TreeNode*, int)>;
        int minDepth(TreeNode* root, int INF = 1e9 + 7) {
            fun go = [&](auto node, int depth) {
                if (!node->left && !node->right)
                    return depth;
                auto L = node->left  ? go(node->left,  depth + 1) : INF,
                        R = node->right ? go(node->right, depth + 1) : INF;
                return min(L, R);
            };
            return root ? go(root, 1) : 0;
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using Queue = queue<TreeNode*>;
        int minDepth(TreeNode* root, int depth = 1) {
            if (!root)
                return 0;
            Queue q{{{ root }}};
            while (q.size()) {
                int k = q.size();
                while (k--) {
                    auto cur = q.front(); q.pop();
                    if (!cur->left && !cur->right)
                        return depth;
                    if (cur->left)  q.push(cur->left);
                    if (cur->right) q.push(cur->right);
                }
                ++depth;
            }
            return -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
