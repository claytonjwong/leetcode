/*
 * 799. Champagne Tower
 *
 * Q: https://leetcode.com/problems/champagne-tower/
 * A: https://leetcode.com/problems/champagne-tower/discuss/118694/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <vector>

using namespace std;

namespace BottomUp {
    class Solution {
    public:
        using VD = vector<double>;
        using VVD = vector<VD>;
        double champagneTower(int K, int M, int N) {
            VVD dp(M + 1, VD(N + 2));
            dp[0][0] = K;
            for (auto i{ 0 }; i < M; ++i) {
                for (auto j{ 0 }; j <= N; ++j) {
                    if (dp[i][j] <= 1.0)  // no overflow
                        continue;
                    auto half = (dp[i][j] - 1.0) / 2;  // -1.0 to fill cup i,j
                    dp[i + 1][j]     += half;
                    dp[i + 1][j + 1] += half;
                }
            }
            return min(dp[M][N], 1.0);
        }
    };
}
namespace MemOpt {
    class Solution {
    public:
        using VD = vector<double>;
        double champagneTower(int K, int M, int N) {
            VD pre(N + 2);
            pre[0] = K;
            while (M--) {
                VD cur(N + 2);
                for (auto j{ 0 }; j <= N; ++j) {
                    if (pre[j] <= 1.0)  // no overflow
                        continue;
                    auto half = (pre[j] - 1.0) / 2;  // -1.0 to fill cup i,j
                    cur[j]     += half;
                    cur[j + 1] += half;
                }
                swap(pre, cur);
            }
            return min(pre[N], 1.0);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
