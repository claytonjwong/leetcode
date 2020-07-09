/*
 * 662. Maximum Width of Binary Tree
 *
 * Q: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * A: https://leetcode.com/problems/maximum-width-of-binary-tree/discuss/727201/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

namespace Recursive {
    class Solution {
        using Map = unordered_map<int, int>;
        int max;
        int go(TreeNode* root, int depth = 0, int i = 1, Map&& m = {}) {
            if (m.find(depth) == m.end())
                m[depth] = i; // first i-th value 👀 seen at this depth is ⭐️ min i-th value at this depth
            max = std::max(max, i - m[depth] + 1); // 🎯 subtract each i-th value from min i-th value to find max width (+1 for i..j inclusive)
            if (root->left)  go(root->left,  depth + 1, 2 * (i - m[depth]) + 1, move(m)); // 🚫 avoid int overflow by subtracting each i-th value by the min per depth
            if (root->right) go(root->right, depth + 1, 2 * (i - m[depth]) + 2, move(m)); // 🚫 avoid int overflow by subtracting each i-th value by the min per depth
            return max;
        }
    public:
        int widthOfBinaryTree(TreeNode* root) {
            max = 0;
            return root ? go(root) : 0;
        }
    };
}

namespace Iterative {
    class Solution {
    public:
        using Map = unordered_map<int, int>;
        using Queue = queue<tuple<TreeNode*, int>>;
        int widthOfBinaryTree(TreeNode* root, Map m = {}, int depth = 0, int max = 0) {
            Queue q{{{ root, 1 }}};
            while (q.size()) {
                int K = q.size();
                while (K--) {
                    auto [root, i] = q.front(); q.pop();
                    if (m.find(depth) == m.end())
                        m[depth] = i; // first i-th value 👀 seen at this depth is ⭐️ min i-th value at this depth
                    max = std::max(max, i - m[depth] + 1); // 🎯 subtract each i-th value from min i-th value to find max width (+1 for i..j inclusive)
                    if (root->left)  q.push({ root->left,  2 * (i - m[depth]) + 1 }); // 🚫 avoid int overflow by subtracting each i-th value by the min per depth
                    if (root->right) q.push({ root->right, 2 * (i - m[depth]) + 2 }); // 🚫 avoid int overflow by subtracting each i-th value by the min per depth
                }
                ++depth;
            }
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
