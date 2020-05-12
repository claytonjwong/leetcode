/*
 * 1443. Minimum Time to Collect All Apples in a Tree
 *
 * Q: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
 * A: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/discuss/627010/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

namespace BellmanFord {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        using Map = unordered_map<int, Set>;
        int minTime(int N, VVI& E, vector<bool>& A, Map m = {}, int ans = 0) {
            VI dist(N, 1e9 + 7),
               prev(N);
            dist[0] = 0;
            while (N--) {
                for (auto& edge: E) {
                    auto [u, v] = tie(edge[0], edge[1]);
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        prev[v] = u;
                    }
                }
            }
            Set seen{ 0 };
            for (auto i{ 0 }; i < A.size(); ++i) {
                if (!A[i])
                    continue; // no apple ❌
                auto steps{ 0 };
                for (auto j{ i }; seen.find(j) == seen.end(); j = prev[j])
                    seen.insert(j), ++steps;
                ans += 2 * steps; // 2x steps to first seen node 🎯
            }
            return ans;
        }
    };
}

namespace SPFA {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        using Map = unordered_map<int, Set>;
        int minTime(int N, VVI& E, vector<bool>& A, Map m = {}, int ans = 0) {
            VI dist(N, 1e9 + 7),
               prev(N);
            for (auto edge: E) {
                auto [u, v] = tie(edge[0], edge[1]);
                m[u].insert(v);
                m[v].insert(u);
            }
            dist[0] = 0;
            queue<int> q{{ 0 }};
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto v: m[u]) {
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        prev[v] = u;
                        q.push(v);
                    }
                }
            }
            Set seen{ 0 };
            for (auto i{ 0 }; i < N; ++i) {
                if (!A[i])
                    continue; // no apple ❌
                auto steps{ 0 };
                for (auto j{ i }; seen.find(j) == seen.end(); j = prev[j])
                    seen.insert(j), ++steps;
                ans += 2 * steps; // 2x steps to first seen node 🎯
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
