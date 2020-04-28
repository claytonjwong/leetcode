/*
 * 221. Maximal Square
 *
 * Q: https://leetcode.com/problems/maximal-square/
 * A: https://leetcode.com/problems/maximal-square/discuss/600365/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Naive {
    class Solution {
    public:
        using VC = vector<char>;
        using VVC = vector<VC>;
        int maximalSquare(VVC& A, int max = 0) {
            auto M = A.size(),
                    N = M ? A[0].size() : 0;
            VVC row(M, VC(N)),
                    col(M, VC(N));
            auto ok = [&](auto i, auto j, auto k) {
                if (i + k >= M || j + k >= N)
                    return false;
                auto row{ 0 },
                     col{ 0 };
                for (auto u{ i }; u <= i + k; ++u) col += A[u][j + k] == '1';
                for (auto v{ j }; v <= j + k; ++v) row += A[i + k][v] == '1';
                return (row == k + 1 && col == k + 1);
            };
            for (auto i{ 0 }; i < M; ++i) {
                for (auto j{ 0 }; j < N; ++j) {
                    if (A[i][j] == '0')
                        continue;
                    auto k{ 1 };
                    while (ok(i, j, k))
                        ++k;
                    max = std::max(max, k * k);
                }
            }
            return max;
        }
    };
}
namespace TopDown {
    class Solution {
    public:
        using VC = vector<char>;
        using VVC = vector<VC>;
        int maximalSquare(VVC& A, int max = 0) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            VVC m(M + 1, VC(N + 1, -1));
            for (auto i{ M }; i > -1; --i)
                for (auto j{ N }; j > -1; --j)
                    go(A, i, j, max, m);
            return max * max;
        }
    private:
        int go(VVC& A, int i, int j, int& max, VVC& m) {
            if (m[i][j] > -1)
                return m[i][j];
            if (!i || !j)
                return m[i][j] = 0;
            auto best{ 0 };
            if (A[i - 1][j - 1] == '1')
                best = 1 + min({
                    go(A, i - 1, j - 1, max, m),
                    go(A, i - 1, j, max, m),
                    go(A, i, j - 1, max, m)
                });
            max = std::max(max, best);
            return m[i][j] = best;
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VC = vector<char>;
        using VVC = vector<VC>;
        int maximalSquare(VVC& A, int max = 0) {
            auto M = A.size(),
                 N = M ? A[0].size() : 0;
            VVC dp(M + 1, VC(N + 1));
            for (auto i{ 1 }; i <= M; ++i)
                for (auto j{ 1 }; j <= N; ++j)
                    if (A[i - 1][j - 1] == '1')
                        dp[i][j] = 1 + min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }),
                        max = std::max(max, dp[i][j] * dp[i][j]);
            return max;
        }
    };
}
namespace BottomUpMemoryOptimized {
    class Solution {
    public:
        using VC = vector<char>;
        using VVC = vector<VC>;
        int maximalSquare(VVC& A, int max = 0) {
            auto M = A.size(),
                 N = M ? A[0].size() : 0;
            VC pre(N + 1),
               cur(N + 1);
            for (auto i{ 1 }; i <= M; ++i, swap(pre, cur))
                for (auto j{ 1 }; j <= N; ++j)
                    if (A[i - 1][j - 1] == '1')
                        cur[j] = 1 + min({ pre[j - 1], pre[j], cur[j - 1] }),
                        max = std::max(max, cur[j] * cur[j]);
                    else
                        cur[j] = 0;
            return max;
        }
    };
}

int main() {
    TopDown::Solution solution;
//    BottomUp::Solution::VVC A{
//        {'1','0','1','0','0',},
//        {'1','0','1','1','1',},
//        {'1','1','1','1','1',},
//        {'1','0','1','1','1',},
//    };
    TopDown::Solution::VVC A{
            {'1','0','1','0','0',},
            {'1','0','1','1','1',},
            {'1','1','1','1','1',},
            {'1','0','0','1','0',},
    };
    cout << solution.maximalSquare(A) << endl;
    return 0;
}
