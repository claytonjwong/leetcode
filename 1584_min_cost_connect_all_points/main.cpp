/*
 * 1584. Min Cost to Connect All Points
 *
 * Q: https://leetcode.com/problems/min-cost-to-connect-all-points/
 * A: https://leetcode.com/problems/min-cost-to-connect-all-points/discuss/850003/Javascript-Python3-C%2B%2B-Kruskal's-MST
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
