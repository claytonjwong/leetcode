/*
 * 743. Network Delay Time
 *
 * Q: https://leetcode.com/problems/network-delay-time/
 * A: https://leetcode.com/problems/network-delay-time/discuss/656011/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace BellmanFord {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int networkDelayTime(VVI& E, int N, int K, int INF = 1e9 + 7) {
            VI dist(N + 1, INF);   // +1 for 1-based indexing
            dist[0] = dist[K] = 0; // dist = 0 for sentinel at index 0 and node K
            while (--N) {
                for (auto& edge: E) {
                    auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }
            auto max = *max_element(dist.begin(), dist.end());
            return max < INF ? max : -1;
        }
    };
}

namespace SPFA {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Graph = vector<vector<pair<int, int>>>;
        int networkDelayTime(VVI& E, int N, int K, int INF = 1e9 + 7) {
            Graph adj(N + 1); // +1 for 1-based indexing
            for (auto& edge: E) {
                auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                adj[u].push_back({ v, w });
            }
            VI dist(N + 1, INF);   // +1 for 1-based indexing
            dist[0] = dist[K] = 0; // set init dist = 0 for sentinel at index 0 and for node K
            queue<int> q{{ K }};
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto [v, w]: adj[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push(v);
                    }
                }
            }
            auto max = *max_element(dist.begin(), dist.end());
            return max < INF ? max : -1;
        }
    };
}

namespace Dijkstra {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Pair = pair<int, int>;
        using Pairs = vector<Pair>;
        using Graph = vector<Pairs>;
        int networkDelayTime(VVI& E, int N, int K, int INF = 1e9 + 7) {
            Graph adj(N + 1); // +1 for 1-based indexing
            for (auto& edge: E) {
                auto [u, v, w] = tie(edge[0], edge[1], edge[2]);
                adj[u].push_back({ v, w });
            }
            VI dist(N + 1, INF);   // +1 for 1-based indexing
            dist[0] = dist[K] = 0; // set init dist = 0 for sentinel at index 0 and for node K
            priority_queue<Pair, Pairs, greater<Pair>> q;
            q.push({ K, 0 });
            while (!q.empty()) {
                auto [u, _] = q.top(); q.pop();
                for (auto [v, w]: adj[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push({ v, dist[v] });
                    }
                }
            }
            auto max = *max_element(dist.begin(), dist.end());
            return max < INF ? max : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
