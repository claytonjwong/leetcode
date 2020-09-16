/*
 * 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
 *
 * Q: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 * A: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/discuss/848649/Javascript-Python3-C%2B%2B-Union-Find-%2B-Greedy
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<int(VI&, int)>;
    int maxNumEdgesToRemove(int N, VVI& E, int same = 0) {
        transform(E.begin(), E.end(), E.begin(), [](auto& edge) {
            auto [ _, u, v ] = tie(edge[0], edge[1], edge[2]);
            return VI{ _, u - 1, v - 1 };                          // ⭐️ -1 for 1-based to 0-based indexing
        });
        VI A(N); iota(A.begin(), A.end(), 0);                      // 🙂 parent representatives of disjoint sets for Alice
        VI B(N); iota(B.begin(), B.end(), 0);                      // 🙂 parent representatives of disjoint sets for Bob
        fun find = [&](auto& P, auto x) {
            return P[x] = P[x] == x ? x : find(P, P[x]);
        };
        auto _union = [&](auto& P, auto a, auto b) {
            a = find(P, a);
            b = find(P, b);
            if (a == b)
                return 1;
            P[a] = b;  // arbitrary choice
            return 0;
        };
        for (auto& edge: E) {
            auto [ type, u, v ] = tie(edge[0], edge[1], edge[2]);
            if (type == 3) same += _union(A, u, v) | _union(B, u, v);  // 🥇 first: 🔗 union shared edges for Alice and Bob
        }
        for (auto& edge: E) {
            auto [ type, u, v ] = tie(edge[0], edge[1], edge[2]);
            if (type == 1) same += _union(A, u, v);                    // 🥈 second: 🔗 union edges for Alice
            if (type == 2) same += _union(B, u, v);                    //            🔗 union edges for Bob
        }
        // 🎯 is there a single connected component for Alice and Bob?
        // if so, return the amount of edges which redundantly connect
        // to each same connected component for Alice and Bob
        return all_of(A.begin(), A.end(), [&](auto x) { return find(A, 0) == find(A, x); }) &&
               all_of(B.begin(), B.end(), [&](auto x) { return find(B, 0) == find(B, x); }) ? same : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
