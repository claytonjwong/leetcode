/*
 * 1522. Diameter of N-Ary Tree
 *
 * Q: https://leetcode.com/problems/diameter-of-n-ary-tree/
 * A: https://leetcode.com/problems/diameter-of-n-ary-tree/discuss/755080/Javascript-Python3-C%2B%2B-post-order-traversal
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
};

class Solution {
    int best = 0;
    int go(Node* root, int next = 0) {
        if (!root) // 🛑 base case
            return 0;
        for (auto child: root->children) { // 🚀 DFS explore children
            auto cur = go(child);
            best = std::max(best, cur + next); // 🎯 best pair of current local maximums
            next = std::max(cur, next);
        }
        return 1 + next; // ⭐️ next candidate accumulated as the recursive stack unwinds
    }
public:
    int diameter(Node* root) {
        go(root);
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
