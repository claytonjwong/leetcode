/*
 * 1519. Number of Nodes in the Sub-Tree With the Same Label
 *
 * Q: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
 * A: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/discuss/746462/Javascript-Python3-C%2B%2B-post-order-traversal
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    VI ans;
    VVI adj;
    string keys;
    Set seen;
    VI go(int u = 0, VI next = VI(26)) {
        seen.insert(u); // seen u 👀
        for (auto v: adj[u]) {
            if (seen.find(v) != seen.end()) // 🚫 skip previously seen parent 👀
                continue;
            auto cur = go(v); // 🚀 explore child v
            for (auto i{ 0 }; i < 26; ++i) // 🎯 post-order accumulate keys for child node v
                next[i] += cur[i];
        }
        ans[u] = ++next[keys[u] - 'a']; // 🎯 increment key for current node u
        return next;
    }
public:
    VI countSubTrees(int N, VVI& E, string keys_) {
        ans = VI(N);
        adj = VVI(N);
        keys = keys_;
        for (auto& edge: E) {
            auto [u, v] = tie(edge[0], edge[1]);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        go();
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
