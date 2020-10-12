/*
 * 1615. Maximal Network Rank
 *
 * Q: https://leetcode.com/problems/maximal-network-rank/
 * A: https://leetcode.com/problems/maximal-network-rank/discuss/888884/Kt-Js-Py3-Cpp-Brute-Force
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, unordered_set<int>>;
    int maximalNetworkRank(int N, VVI& E, Map adj = {}, int best = 0) {
        auto degree = [&](auto v) { return int(adj[v].size()); };
        for (auto& edge: E) {
            auto [u, v] = tie(edge[0], edge[1]);
            adj[u].insert(v);
            adj[v].insert(u);
        }
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ i + 1 }; j < N; ++j)
                best = max(best, degree(i) + degree(j) - (adj[i].find(j) != adj[i].end()));
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
