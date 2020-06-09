/*
 * 518. Coin Change 2
 *
 * Q: https://leetcode.com/problems/coin-change-2/
 * A: https://leetcode.com/problems/coin-change-2/discuss/677893/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
        using VI = vector<int>;
        int N, T;
        VI A;
        int go(int i, int t) {
            if (!t)
                return 1;
            if (i == N)
                return 0;
            return (0 <= t - A[i] ? go(i, t - A[i]) : 0) + go(i + 1, t); // with A[i] ✅  + without A[i] ❌
        }
    public:
        int change(int amount, VI& coins, int ans = 0) {
            T = amount;
            A = coins;
            N = A.size();
            return go(0, T);
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        int N;
        VI A;
        int go(int i, int t, VVI&& m = VVI(500, VI(5001, -1))) {
            if (m[i][t] > -1)
                return m[i][t];
            if (!t)
                return m[i][t] = 1;
            if (i == N)
                return m[i][t] = 0;
            return m[i][t] = (0 <= t - A[i] ? go(i, t - A[i], move(m)) : 0) + go(i + 1, t, move(m)); // with A[i] ✅  + without A[i] ❌
        }
    public:
        int change(int T, VI& coins, int ans = 0) {
            A = coins;
            N = A.size();
            return go(0, T);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int change(int T, VI& A) {
            int N = A.size();
            VVI dp(N + 1, VI(T + 1));
            for (auto i{ 0 }; i <= N; ++i)
                dp[i][0] = 1;
            for (auto i{ 1 }; i <= N; ++i)
                for (auto t{ 1 }; t <= T; ++t)
                    dp[i][t] = (0 <= t - A[i - 1] ? dp[i][t - A[i - 1]] : 0) + dp[i - 1][t]; // with A[i] ✅  + without A[i] ❌
            return dp[N][T];
        }
    };
}

namespace BottomUpMemOpt1 {
    class Solution {
    public:
        using VI = vector<int>;
        int change(int T, VI& A) {
            int N = A.size();
            VI pre(T + 1),
               cur{ pre };
            pre[0] = 1;
            for (auto i{ 1 }; i <= N; ++i) {
                cur[0] = 1;
                for (auto t{ 1 }; t <= T; ++t)
                    cur[t] = (0 <= t - A[i - 1] ? cur[t - A[i - 1]] : 0) + pre[t]; // with A[i] ✅  + without A[i] ❌
                swap(pre, cur);
            }
            return pre[T];
        }
    };
}

namespace BottomUpMemOpt2 {
    class Solution {
    public:
        using VI = vector<int>;
        int change(int T, VI& A) {
            int N = A.size();
            VI dp(T + 1);
            dp[0] = 1;
            for (auto i{ 1 }; i <= N; ++i)
                for (auto t{ 1 }; t <= T; ++t)
                    dp[t] = (0 <= t - A[i - 1] ? dp[t - A[i - 1]] : 0) + dp[t]; // with A[i] ✅  + without A[i] ❌
            return dp[T];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
