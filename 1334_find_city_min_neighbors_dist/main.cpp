/*
 * 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance
 *
 * Q: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * A: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/discuss/517093/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Tuple = tuple<int, int>;
    using Graph = unordered_map<int, vector<Tuple>>;
    static constexpr int INF = 1e9 + 7;
    int findTheCity(int N, VVI& edges, int threshold) {
        VVI dist(N, VI(N, INF));
        for (auto i = 0; i < N; ++i)
            dist[i][i] = 0;
        Graph G;
        for (auto& e: edges) {
            auto [u, v, w] = tie(e[0], e[1], e[2]);
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        auto minCity = [&]() {
            int min = INF, city = -1;
            for (auto i = 0; i < N; ++i) {
                auto cnt = 0;
                for (auto j = 0; j < N; ++j)
                    if (i != j && dist[i][j] <= threshold)
                        ++cnt;
                if (min >= cnt)
                    min = cnt,
                    city = i;
            }
            return city;
        };
        auto dijkstra = [&](int start, VI& dist) {
            struct Cmp {
                bool operator()(const Tuple& a, const Tuple& b) const {
                    return std::get<1>(a) < std::get<1>(b);
                }
            };
            priority_queue<Tuple, vector<Tuple>, Cmp> q;
            q.push({start, 0});
            while (!q.empty()) {
                auto [u, cost] = q.top(); q.pop();
                if (dist[u] < cost)
                    continue;
                for (auto [v, w]: G[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push({v, w});
                    }
                }
            }
        };
        auto bellmanFord = [&](VI& dist) {
            for (auto k = 1; k < N; ++k) {
                for (auto& e: edges) {
                    auto [u, v, w] = tie(e[0], e[1], e[2]);
                    if (dist[u] > dist[v] + w)
                        dist[u] = dist[v] + w;
                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }
        };
        auto SPFA = [&](int start, VI& dist) {
            queue<int> q({start});
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto [v, w]: G[u]) {
                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                        q.push(v);
                    }
                }
            }
        };
        for (auto i = 0; i < N; ++i)
            // dijkstra(i, dist[i]);
            // bellmanFord(dist[i]);
            SPFA(i, dist[i]);
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
