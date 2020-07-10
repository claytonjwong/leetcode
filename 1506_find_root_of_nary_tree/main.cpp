/*
 * 1506. Find Root of N-Ary Tree
 *
 * Q: https://leetcode.com/problems/find-root-of-n-ary-tree/
 * A: https://leetcode.com/problems/find-root-of-n-ary-tree/discuss/729168/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
};

namespace Naive {
    class Solution {
    public:
        using Nodes = vector<Node*>;
        using Set = unordered_set<Node*>;
        Node* findRoot(Nodes tree, Set children = {}) {
            for (auto node: tree)
                for (auto child: node->children)
                    children.insert(child);
            tree.erase(remove_if(tree.begin(), tree.end(), [&](auto node) { return children.find(node) != children.end(); }), tree.end());
            return tree[0]; // 🎯 root node is the only node which is *not* a child
        }
    };
}

namespace MemOpt {
    class Solution {
    public:
        using Nodes = vector<Node*>;
        Node* findRoot(Nodes tree, int x = 0) {
            for (auto node: tree) {
                x ^= node->val; // 🎯 root node is only xor'ed once here, 🚫 child nodes are xor'ed once here and once below
                for (auto child: node->children)
                    x ^= child->val; // 🚫 child nodes are xor'ed a second time here
            }
            tree.erase(remove_if(tree.begin(), tree.end(), [&](auto node) { return node->val != x; }), tree.end());
            return tree[0];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
