/*
 * 799. Champagne Tower
 *
 * Q: https://leetcode.com/problems/champagne-tower/
 * A: https://leetcode.com/problems/champagne-tower/discuss/118694/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDownMemo {
    class Solution {
    public:
        using Map = unordered_map<string, double>;
        using fun = function<double(int, int)>;
        double champagneTower(int K, int M, int N, Map m = {}) {
            fun go = [&](int i, int j) {
                stringstream key; key << i << "," << j;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];                               // 🤔 memo
                else if (!i && !j)
                    return m[key.str()] = static_cast<double>(K);      // 🛑 base case: glass at row 0 column 0 has K poured through it
                if (!i || j < 0)
                    return m[key.str()] = 0.0;                         // 🚫 non-existent parent glass has 0.0 poured through it
                auto L = go(i - 1, j - 1),
                     R = go(i - 1, j);
                // ⭐️ each parent glass above-and-to-the-(L)eft/(R)ight either overflow when the amount poured exceeds 1.0 xor do *not* overflow when the amount poured does *not* exceed 1.0
                // 💎 -1.0 since parent glass above consumes at-most 1.0 of the pour and div 2 when overflow occurs, because half overflows on each side of the parent glass
                return m[key.str()] = (1.0 <= L ? (L - 1.0) / 2 : 0)
                                    + (1.0 <= R ? (R - 1.0) / 2 : 0);
            };
            go(M, max(M, N));                                          // 🌟 since the glasses above-and-to-the-right potentially contribute to the amount poured to M, N we choose N to be the maximum of M, N
            return min(go(M, N), 1.0);
        }
    };
}
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
