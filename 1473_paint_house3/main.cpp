/*
 * 1473. Paint House III
 *
 * Q: https://leetcode.com/problems/paint-house-iii/
 * A: https://leetcode.com/problems/paint-house-iii/discuss/695337/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace DFS {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        using VVVI = vector<VVI>;
        VI A;
        VVI cost;
        int N, K;
        static constexpr auto INF = int(1e9 + 7);
        int go(int i, int color, int t, int min = INF) {
            auto diffHood = [=](auto cand) { return int(cand != color); }; // different neighborhood 🏘 🏘
            if (t < 0)
                return INF; // invalid target t neighborhoods ❌
            if (i == N)
                return !t ? 0 : INF; // target 🎯 t == 0
            if (A[i])
                return go(i + 1, A[i], t - diffHood(A[i])); // A[i] is already painted, thus A[i] is the only j-th color under consideration
            for (auto j{ 0 }; j < K; ++j) // j-th color
                min = std::min(min, cost[i][j] + go(i + 1, j + 1, t - diffHood(j + 1))); // j + 1 for 1-based indexing
            return min;
        }
    public:
        int minCost(VI& A_, VVI& cost_, int N_, int K_, int T) {
            A = A_;       // houses
            cost = cost_; // cost
            N = N_;       // N houses
            K = K_;       // K colors
            auto min = go(0, 0, T);
            return min < INF ? min : -1;
        }
    };
}

namespace DFS_Memo {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        using VVVI = vector<VVI>;
        VI A;
        VVI cost;
        int N, K;
        static constexpr auto INF = int(1e9 + 7);
        int go(int i, int color, int t, VVVI&& m = VVVI(100 + 1, VVI(20 + 1, VI(100 + 1, -1))), int min = INF) {
            auto diffHood = [=](auto cand) { return int(cand != color); }; // different neighborhood 🏘 🏘
            if (t < 0)
                return INF; // invalid target t neighborhoods ❌
            if (m[i][color][t] > -1)
                return m[i][color][t]; // memo 🤔
            if (i == N)
                return m[i][color][t] = !t ? 0 : INF; // target 🎯 t == 0
            if (A[i])
                return m[i][color][t] = go(i + 1, A[i], t - diffHood(A[i]), move(m)); // A[i] is already painted, thus A[i] is the only j-th color under consideration
            for (auto j{ 0 }; j < K; ++j) // j-th color
                min = std::min(min, cost[i][j] + go(i + 1, j + 1, t - diffHood(j + 1), move(m))); // j + 1 for 1-based indexing
            return m[i][color][t] = min;
        }
    public:
        int minCost(VI& A_, VVI& cost_, int N_, int K_, int T) {
            A = A_;       // houses
            cost = cost_; // cost
            N = N_;       // N houses
            K = K_;       // K colors
            auto min = go(0, 0, T);
            return min < INF ? min : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
