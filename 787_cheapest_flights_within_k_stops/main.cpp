/*
 * 787. Cheapest Flights Within K Stops
 *
 * Q: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * A: https://leetcode.com/problems/cheapest-flights-within-k-stops/discuss/690997/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Set = unordered_set<int>;
    using Adj = unordered_map<int, vector<tuple<int, int>>>;
    Adj adj;
    int dst, hops, best;
    void go(int u, int k, int cost = 0, Set&& seen = {}) {
        if (u == dst)
            best = min(best, cost); // best is the minimum cost 🎯
        if (u == dst || !k)
            return;
        if (!seen.insert(u).second) // 👀 ✅ forward-tracking
            return;
        for (auto [v, w]: adj[u])
            if (seen.find(v) == seen.end() && cost + w < best) // pruning condition: cost + w < best 🤔
                go(v, k - 1, cost + w, move(seen));
        seen.erase(u); // 👀 ❌ back-tracking
    }
public:
    int findCheapestPrice(int _, VVI& edges, int src, int dst_, int hops_, int best_ = int(1e9 + 7)) {
        dst = dst_;
        hops = hops_;
        best = best_;
        for (auto& edge: edges) {
            auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
            adj[u].push_back({v, w});
        }
        go(src, hops + 1);
        return best < int(1e9 + 7) ? best : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
