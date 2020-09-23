/*
 * 1584. Min Cost to Connect All Points
 *
 * Q: https://leetcode.com/problems/min-cost-to-connect-all-points/
 * A: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/850003/Javascript-Python3-C%2B%2B-Kruskal's-MST
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <queue>

using namespace std;

namespace Kruskal {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int)>;
        int minCostConnectPoints(VVI& A, VVI E = {}, int cost = 0) {
            int N = A.size();
            VI P(N); iota(P.begin(), P.end(), 0);                                    // 🙂 parent representatives of disjoint sets
            for (auto u{ 0 }; u < N; ++u) {
                for (auto v{ u + 1 }; v < N; ++v) {
                    auto w = abs(A[u][0] - A[v][0]) + abs(A[u][1] - A[v][1]);
                    E.push_back({ u, v, w });                                        // 🗺 edge u, v with weight w 💰
                }
            }
            sort(E.begin(), E.end(), [](auto& a, auto& b) { return a[2] < b[2]; });  // ⭐️ sort edges by weight w 💰
            fun find = [&](auto x) { return P[x] = x == P[x] ? x : find(P[x]); };
            auto _union = [&](auto a, auto b) {
                a = find(a);
                b = find(b);
                if (a == b)
                    return false;
                P[a] = b;                                                            // 🎲 arbitrary choice
                return true;
            };
            return accumulate(E.begin(), E.end(), 0, [&](auto total, auto& edge) {
                auto [ u, v, w ] = tie(edge[0], edge[1], edge[2]);
                return total + (_union(u, v) ? w : 0);                               // 🎯 sum of minimum edge weights w 💰 to construct Kruskal's MST 🌲
            });
        }
    };
}
namespace Prim_Naive {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        int minCostConnectPoints(VVI& A, Set tree = {}, Set cand = {}, int INF = 1e9 + 7, int cost = 0) {
            int N = A.size();
            generate_n(inserter(cand, cand.end()), N, [i = -1]() mutable { return ++i; });  // 📬 available candidate vertices (to be greedily added to MST)
            tree.insert(0);                                                                 // 🎲 arbitrary choice to start with vertex 0 😵
            cand.erase(0);
            while (cand.size()) {                                                           // 📬 while there are candidates vertices available
                auto minCost{ INF };                                                        // 🔍 find the 💰 minimum cost 📬 candidate vertice v
                auto minVertex{ -1 };
                for (auto u: tree) {                                                        // for each u already in the tree 🌲
                    auto[ x1, y1 ] = tie(A[u][0], A[u][1]);
                    for (auto v: cand) {                                                    // 📬 👀 see if v is the 💰 minimum cost available candidate vertex
                        auto[ x2, y2 ] = tie(A[v][0], A[v][1]);
                        auto cost = abs(x1 - x2) + abs(y1 - y2);
                        if (minCost > cost) {                                               // 💰 greedily update minimum cost and its vertex v
                            minCost = cost;
                            minVertex = v;
                        }
                    }
                }
                cost += minCost;                                                            // 💰 add minimum cost of vertex v to 🎯 ongoing accumulated minimum cost
                cand.erase(minVertex), tree.insert(minVertex);                              // remove vertex v from candidates 📬 👉 📭  and add vertex v to tree 🌲
            }
            return cost;                                                                    // return 🎯 ongoing accumulated minimum cost
        }
    };
}
namespace Prim_Heap {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        using Pair = pair<int, int>;
        using Pairs = vector<Pair>;
        using Queue = priority_queue<Pair, Pairs, std::greater<Pair>>;
        int minCostConnectPoints(VVI& A, Set cand = {}, int INF = 1e9 + 7, int total = 0) {
            int N = A.size();
            generate_n(inserter(cand, cand.end()), N - 1, [i = 0]() mutable { return ++i; });
            VVI E(N, VI(N));
            for (auto u{ 0 }; u < N; ++u) {
                auto [x1, y1] = tie(A[u][0], A[u][1]);
                for (auto v{ u + 1 }; v < N; ++v) {
                    auto [x2, y2] = tie(A[v][0], A[v][1]);
                    auto cost = abs(x1 - x2) + abs(y1 - y2);
                    E[u][v] = cost;
                    E[v][u] = cost;
                }
            }
            auto s = 0;
            Queue q;
            VI best(N, INF);
            for (auto v{ 1 }; v < N; ++v) {
                if (best[v] > E[s][v]) {
                    best[v] = E[s][v];
                    q.push({ best[v], v });
                }
            }
            while (cand.size()) {
                auto [cost, u] = q.top(); q.pop();
                if (cand.find(u) == cand.end())
                    continue;
                cand.erase(u);
                total += cost;
                for (auto v{ 0 }; v < N; ++v) {
                    if (cand.find(v) == cand.end())
                        continue;
                    if (best[v] > E[u][v]) {
                        best[v] = E[u][v];
                        q.push({ best[v], v });
                    }
                }
            }
            return total;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
