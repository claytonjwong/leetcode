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

namespace DFS_BT {
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
                return; // target T reached or k-hops exhausted: stop 🛑
            seen.insert(u); // 👀 ✅ forward-tracking
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
}

namespace DFS {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Adj = unordered_map<int, vector<tuple<int, int>>>; // u -> [v, w] == edge u -> v with cost w
        Adj adj;
        int T;
        static constexpr auto INF = int(1e9 + 7);
        int go(int u, int k, int min = INF) {
            if (u == T)
                return 0; // target T 🎯
            if (!k)
                return INF; // all k hops exhaused ❌
            for (auto [v, w]: adj[u])
                min = std::min(min, w + go(v, k - 1)); // dfs edge u -> v with cost w
            return min;
        }
    public:
        int findCheapestPrice(int _, VVI& E, int start, int T_, int hops) {
            T = T_;
            for (auto& edge: E) {
                auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                adj[u].push_back({v, w});
            }
            auto ans = go(start, hops + 1);
            return ans < INF ? ans : -1;
        }
    };
}

namespace DFS_Memo {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Adj = unordered_map<int, vector<tuple<int, int>>>; // u -> [v, w] == edge u -> v with cost w
        Adj adj;
        int T;
        VVI m;
        static constexpr auto INF = int(1e9 + 7);
        int go(int u, int k, int min = INF) {
            if (m[u][k] > -1)
                return m[u][k]; // memo 🤔
            if (u == T)
                return m[u][k] = 0; // target T 🎯
            if (!k)
                return m[u][k] = INF; // all k hops exhausted ❌
            for (auto [v, w]: adj[u])
                min = std::min(min, w + go(v, k - 1)); // dfs edge u -> v with cost w
            return m[u][k] = min;
        }
    public:
        int findCheapestPrice(int N, VVI& E, int start, int T_, int hops) {
            T = T_;
            m = VVI(N, VI(hops + 2, -1)); // +2 because for V vertices there are V+1 edges and +1 for the memo itself to be 0..hops+1 inclusive
            for (auto& edge: E) {
                auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                adj[u].push_back({v, w});
            }
            auto ans = go(start, hops + 1);
            return ans < INF ? ans : -1;
        }
    };
}

namespace BF {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int findCheapestPrice(int N, VVI& E, int start, int T, int hops, int INF = int(1e9 + 7)) {
            auto k = hops + 1;
            VI pre(N, INF);
            pre[start] = 0;
            while (k--) { // relax all edges k times
                // bellman-ford: dist[v] = min(dist[v], dist[u] + w) ie. relax edge u,v of cost w
                // however, use previous and current to avoid overwritting our previous optimal edge relaxations
                // which we still need to read from in order to derive our current optimal edge relaxations for each k-th hop
                auto cur{ pre }; // derive current from previous 🤔 ie. update current optimal edge relaxations based upon previous optimal edge relaxations
                for (auto& edge: E) {
                    auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                    cur[v] = min(cur[v], pre[u] + w); // relax all edges u,v of cost w for optimal distance to v 🎯
                }
                swap(pre, cur); // persist current as previous via swap 🤔
            }
            return pre[T] < INF ? pre[T] : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
