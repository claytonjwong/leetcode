/*
 * 1140. Stone Game II
 *
 * Q: https://leetcode.com/problems/stone-game-ii/
 * A: https://leetcode.com/problems/stone-game-ii/discuss/713502/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

namespace TopDownBruteForce {
    class Solution {
        using VI = vector<int>;
        VI A;
        int N;
        int go(int i, int k, int total, int take = 0, int max = 0) {
            for (auto j{ i }, stones{ 1 }; j < i + 2 * k && j < N; ++j, ++stones) // take each j-th stone until 🛑 base case: j == N
                max = std::max(max, total - go(j + 1, std::max(k, stones), total - (take += A[j]))); // 🎯 max my score minus max your score
            return max;
        }
    public:
        int stoneGameII(VI& A_) {
            A = A_;
            N = A.size();
            return go(0, 1, accumulate(A.begin(), A.end(), 0));
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        using Map = unordered_map<int, unordered_map<int, int>>;
        VI A;
        int N;
        int go(int i, int k, int total, Map&& m = {}, int take = 0, int max = 0) {
            if (m[i][k])
                return m[i][k]; // 🤔 memo
            for (auto j{ i }, stones{ 1 }; j < i + 2 * k && j < N; ++j, ++stones) // take each j-th stone until 🛑 base case: j == N
                max = std::max(max, total - go(j + 1, std::max(k, stones), total - (take += A[j]), move(m))); // 🎯 max my score minus max your score
            return m[i][k] = max;
        }
    public:
        int stoneGameII(VI& A_) {
            A = A_;
            N = A.size();
            return go(0, 1, accumulate(A.begin(), A.end(), 0));
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int stoneGameII(VI &A) {
            int N = A.size();
            VVI dp(N + 1, VI(N + 1)); // dp[i][j] == best total possible ending at i using last j from N-1..0 inclusive stones
            VI total(N + 1);
            for (auto i{ N - 1 }; 0 <= i; --i)
                dp[i][N] = total[i] = total[i + 1] +
                                      A[i];  // 🛑  base cases: suffix sums, ie. when j == N, then initial state of "no stones taken"
            for (auto i{ N - 1 }; 0 <= i; --i)
                for (auto j{ N - 1 }; 1 <= j; --j)
                    for (auto k{ 1 }; k <= 2 * j && i + k <= N; ++k)
                        dp[i][j] = max(dp[i][j], total[i] - dp[i + k][max(j, k)]); // 🎯 max my score minus max your score
            return dp[0][1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
