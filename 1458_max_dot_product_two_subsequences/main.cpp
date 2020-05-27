/*
 * 1458. Max Dot Product of Two Subsequences
 *
 * Q: https://leetcode.com/problems/max-dot-product-of-two-subsequences/
 * A: https://leetcode.com/problems/max-dot-product-of-two-subsequences/discuss/653625/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        int maxDotProduct(VI& A, VI& B) {
            return go(A, B);
        }
    private:
        int go(VI& A, VI& B, int i = 0, int j = 0) {
            int M = A.size(),
                N = B.size();
            if (i == M || j == N)
                return 0;
            auto max = A[i] * B[j] + std::max(0, go(A, B, i + 1, j + 1)); // case 1: max(0, ...) to add recursive max product only if beneficial
            if (i < M - 1) max = std::max(max, go(A, B, i + 1, j));       // case 2: without A[i], i < M - 1 to ensure subsequence of A is non-empty
            if (j < N - 1) max = std::max(max, go(A, B, i, j + 1));       // case 3: without B[j], j < N - 1 to ensure subsequence of B is non-empty
            return max; // 🎯
        }
    };
}

namespace TopDownWithMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int maxDotProduct(VI& A, VI& B) {
            return go(A, B);
        }
    private:
        static constexpr auto INF = 1e9 + 7;
        int go(VI& A, VI& B, int i = 0, int j = 0, VVI&& m = VVI(501, VI(501, -INF))) {
            if (m[i][j] > -INF)
                return m[i][j];
            int M = A.size(),
                N = B.size();
            if (i == M || j == N)
                return m[i][j] = 0;
            m[i][j] = A[i] * B[j] + std::max(0, go(A, B, i + 1, j + 1, move(m)));    // case 1: max(0, ...) to add recursive max product only if beneficial
            if (i < M - 1) m[i][j] = std::max(m[i][j], go(A, B, i + 1, j, move(m))); // case 2: without A[i], i < M - 1 to ensure subsequence of A is non-empty
            if (j < N - 1) m[i][j] = std::max(m[i][j], go(A, B, i, j + 1, move(m))); // case 3: without B[j], j < N - 1 to ensure subsequence of B is non-empty
            return m[i][j]; // 🎯
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        static constexpr auto INF = int(1e9 + 7);
        int maxDotProduct(VI& A, VI& B) {
            int M = A.size(),
                N = B.size();
            VVI dp(M + 1, VI(N + 1, -INF)); // -INF ensures subsequences of A and B are non-empty
            for (auto i{ 1 }; i <= M; ++i)
                for (auto j{ 1 }; j <= N; ++j)
                    dp[i][j] = max({
                        A[i - 1] * B[j - 1] + max(0, dp[i - 1][j - 1]), // case 1: max(0, ...) to add recursive max product only if beneficial
                        dp[i - 1][j],                                   // case 2: without A[i]
                        dp[i][j - 1],                                   // case 3: without B[j]
                    });
            return dp[M][N]; // 🎯
        }
    };
}

namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        static constexpr auto INF = int(1e9 + 7);
        int maxDotProduct(VI& A, VI& B) {
            int M = A.size(),
                N = B.size();
            VI pre(N + 1, -INF), // -INF ensures subsequences of A and B are non-empty
                    cur{ pre };
            for (auto i{ 1 }; i <= M; ++i) {
                for (auto j{ 1 }; j <= N; ++j)
                    cur[j] = max({
                        A[i - 1] * B[j - 1] + max(0, pre[j - 1]), // case 1: max(0, ...) to add recursive max product only if beneficial
                        pre[j],                                   // case 2: without A[i]
                        cur[j - 1],                               // case 3: without B[j]
                    });
                swap(pre, cur);
            }
            return pre[N]; // 🎯
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
