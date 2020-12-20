/*
 * 1463. Cherry Pickup II
 *
 * Q: https://leetcode.com/problems/cherry-pickup-ii/
 * A: https://leetcode.com/problems/cherry-pickup-ii/discuss/660828/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int, int)>;
        int cherryPickup(VVI& A) {
            int M = A.size(),
                N = A[0].size();
            fun go = [&](auto k, auto i, auto j) {
                auto best = 0;
                if (k == M)
                    return 0;
                for (auto u: VI{ i - 1, i, i + 1 })
                    for (auto v: VI{ j - 1, j, j + 1})
                        if (!(u < 0 || v < 0 || u == M || v == N || v <= u))
                            best = max(best, go(k + 1, u, v));
                return A[k][i] + A[k][j] + best;
            };
            return go(0, 0, N - 1);
        }
    };
}
namespace TopDownMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using fun = function<int(int, int, int)>;
        using Map = unordered_map<string, int>;
        int cherryPickup(VVI& A, Map m = {}) {
            int M = A.size(),
                N = A[0].size();
            fun go = [&](auto k, auto i, auto j) {
                stringstream key; key << k << "," << i << "," << j;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];
                auto best = 0;
                if (k == M)
                    return 0;
                for (auto u: VI{ i - 1, i, i + 1 })
                    for (auto v: VI{ j - 1, j, j + 1})
                        if (!(u < 0 || v < 0 || u == M || v == N || v <= u))
                            best = max(best, go(k + 1, u, v));
                return m[key.str()] = A[k][i] + A[k][j] + best;
            };
            return go(0, 0, N - 1);
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using VVVI = vector<VVI>;
        int cherryPickup(VVI& A) {
            int M = A.size(),
                N = A[0].size();
            VVVI dp(M + 1, VVI(N, VI(N)));
            for (auto k{ M - 1 }; 0 <= k; --k)
                for (auto i{ 0 }; i < N; ++i)
                    for (auto j{ 0 }; j < N; ++j)
                        for (auto u: VI{ i - 1, i, i + 1 })
                            for (auto v: VI{ j - 1, j, j + 1 })
                                if (!(u < 0 || v < 0 || u == M || v == N || v <= u))
                                    dp[k][i][j] = max(dp[k][i][j], A[k][i] + A[k][j] + dp[k + 1][u][v]);
            return dp[0][0][N - 1];
        }
    };
}
namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using VVVI = vector<VVI>;
        int cherryPickup(VVI& A) {
            int M = A.size(),
                N = A[0].size();
            VVVI dp(M + 1, VVI(N, VI(N)));
            VVI pre(N, VI(N));
            for (auto k{ M - 1 }; 0 <= k; --k) {
                VVI cur(N, VI(N));
                for (auto i{ 0 }; i < N; ++i)
                    for (auto j{ 0 }; j < N; ++j)
                        for (auto u: VI{ i - 1, i, i + 1 })
                            for (auto v: VI{ j - 1, j, j + 1 })
                                if (!(u < 0 || v < 0 || u == M || v == N || v <= u))
                                    cur[i][j] = max(cur[i][j], A[k][i] + A[k][j] + pre[u][v]);
                swap(pre, cur);
            }
            return pre[0][N - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
