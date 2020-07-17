/*
 * 1514. Path with Maximum Probability
 *
 * Q: https://leetcode.com/problems/path-with-maximum-probability/
 * A: https://leetcode.com/problems/path-with-maximum-probability/discuss/740901/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

namespace BellmanFord {
    class Solution {
    public:
        using Dist = vector<double>;
        using Edges = vector<vector<int>>;
        using Prob = vector<double>;
        double maxProbability(int N, Edges& E, Prob& A, int s, int t) {
            Dist dist(N);
            dist[s] = 1;
            while (0 < N--) { // ⭐️ relax edges N - 1 times
                auto i{ 0 };
                for (auto& edge: E) {
                    auto [u, v] = tie(edge[0], edge[1]);
                    auto w = A[i++];
                    dist[u] = max(dist[u], dist[v] * w);
                    dist[v] = max(dist[v], dist[u] * w);
                }
            }
            return dist[t];
        }
    };
}

namespace SPFA {
    class Solution {
    public:
        using Dist = vector<double>;
        using Edges = vector<vector<int>>;
        using Prob = vector<double>;
        using Adj = unordered_map<int, vector<tuple<int, double>>>;
        double maxProbability(int N, Edges& E, Prob& A, int s, int t, Adj adj = {}) {
            auto i{ 0 };
            for (auto& edge: E) {
                auto [u, v] = tie(edge[0], edge[1]);
                auto w = A[i++];
                adj[u].push_back({ v, w });
                adj[v].push_back({ u, w });
            }
            Dist dist(N);
            dist[s] = 1;
            queue<int> q{{{ s }}};
            while (q.size()) {
                auto u = q.front(); q.pop();
                for (auto [v, w]: adj[u])
                    if (dist[v] < dist[u] * w)
                        dist[v] = dist[u] * w, q.push(v); // ⭐️ cherry pick v for subsequent edges under consideration to be relaxed
            }
            return dist[t];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
