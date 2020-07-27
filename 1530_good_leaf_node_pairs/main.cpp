/*
 * 1530. Number of Good Leaf Nodes Pairs
 *
 * Q: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
 * A: https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/discuss/758931/Javascript-Python3-C%2B%2B-post-order-Map-distance-count
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
    using Map = unordered_map<int, int>;
    int T, cnt;
    Map go(TreeNode* root, Map m = {}) {
        if (!root)
            return m;
        auto L = go(root->left),
             R = go(root->right);
        if (!root->left && !root->right)
            m[1] = 1; // ⭐️ add leaf node to map with distance 1 and count 1
        for (auto [dist1, cnt1]: L)
            for (auto [dist2, cnt2]: R)
                if (dist1 + dist2 <= T) // 🎯 count "good" leaf node pairs
                    cnt += cnt1 * cnt2;
        // 📌 propagate coalesced child node maps up the recursive stack (dist + 1 because parent is dist + 1 from child)
        for (auto [dist, cnt]: L) m[dist + 1] += cnt;
        for (auto [dist, cnt]: R) m[dist + 1] += cnt;
        return m;
    }
public:
    int countPairs(TreeNode* root, int T_) {
        T = T_;
        cnt = 0;
        go(root);
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
