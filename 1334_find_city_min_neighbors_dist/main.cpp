/*
 * 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 *
 * Q: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * A: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/discuss/517093/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    int findTheCity(int N, VVI& E, int T, int INF = 1e9 + 7) {
        VVI dist(N, VI(N, INF));
        for (auto i = 0; i < N; ++i)
            dist[i][i] = 0;
        auto minCity = [&]() {
            auto low = INF, city = -1;
            for (auto i = 0; i < N; ++i) {
                auto cnt = 0;
                for (auto j = 0; j < N; ++j)
                    if (i != j && dist[i][j] <= T)
                        ++cnt;
                if (low >= cnt) {
                    low = cnt;
                    city = i;
                }
            }
            return city;
        };
        auto bellmanFord = [&](VI& dist) {
            for (auto k = 1; k < N; ++k) {
                for (auto& e: E) {
                    auto [u, v, w] = tie(e[0], e[1], e[2]);
                    if (dist[u] > dist[v] + w) dist[u] = dist[v] + w;
                    if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
                }
            }
        };
//        VVVI adj(N);
//        for (auto& e: E) {
//            auto [u, v, w] = tie(e[0], e[1], e[2]);
//            adj[u].push_back({v, w});
//            adj[v].push_back({u, w});
//        }
//        auto SPFA = [&](VVVI& adj, VI& dist, int i) {
//            dist[i] = 0;
//            queue<int> q{{i}};
//            while (!q.empty()) {
//                auto u = q.front(); q.pop();
//                for (auto& e: adj[u]) {
//                    auto [v, w] = tie(e[0], e[1]);
//                    if (dist[v] > dist[u] + w) {
//                        dist[v] = dist[u] + w;
//                        q.push(v);
//                    }
//                }
//            }
//        };
        for (auto i = 0; i < N; ++i) {
            bellmanFord(dist[i]);
//            SPFA(adj, dist[i], i);
        }
        return minCity();
    }
};

int main() {
    Solution solution;
    auto N = 4;
    Solution::VVI E{
        {0,1,3},
        {1,2,1},
        {1,3,4},
        {2,3,1},
    };
    auto T = 4;
    cout << solution.findTheCity(N, E, T) << endl;
    return 0;
}
