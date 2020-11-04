/*
 * 310. Minimum Height Trees
 *
 * Q: https://leetcode.com/problems/minimum-height-trees/
 * A: https://leetcode.com/problems/minimum-height-trees/discuss/118585/Kt-Js-Py3-Cpp-BFS-Prune-Leaves
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    using Map = unordered_map<int, Set>;
    using Deque = deque<int>;
    VI findMinHeightTrees(int N, VVI& E, Map adj = {}, Deque q = {}) {
        if (E.empty())
            return { 0 };
        for (auto& edge: E) {
            auto [u, v] = tie(edge[0], edge[1]);
            adj[u].insert(v);
            adj[v].insert(u);
        }
        auto isLeaf = [&](auto v) { return adj[v].size() == 1; };
        for (auto v{ 0 }; v < N; ++v)
            if (isLeaf(v))
                q.push_back(v);
        while (2 < N) {
            int k = q.size(); N -= k;
            while (k--) {
                auto u = q.front(); q.pop_front();
                for (auto v: adj[u]) {
                    adj[v].erase(u);
                    if (isLeaf(v))
                        q.push_back(v);
                }
            }
        }
        return { q.begin(), q.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
