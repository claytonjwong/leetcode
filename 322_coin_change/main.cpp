/*
 * 322. Coin Change
 *
 * Q: https://leetcode.com/problems/coin-change/
 * A: https://leetcode.com/problems/coin-change/discuss/677858/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
        using VI = vector<int>;
        VI A;
        int N, T, INF = int(1e9 + 7);
        int go(int i, int t) {
            if (!t)
                return 0;
            if (i == N)
                return INF;
            return min(1 + (0 <= t - A[i] ? go(i, t - A[i]) : INF), go(i + 1, t)); // min(1 + with, without)
        }
    public:
        int coinChange(VI& coins, int amount) {
            A = coins;
            N = A.size();
            T = amount;
            auto ans = go(0, T);
            return ans < INF ? ans : -1;
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        using VVI = vector<VI>;
        VI A;
        int N, T, INF = int(1e9 + 7);
        int go(int i, int t, VVI& m) {
            if (m[i][t] > -1)
                return m[i][t];
            if (!t)
                return m[i][t] = 0;
            if (i == N)
                return m[i][t] = INF;
            return m[i][t] = min(1 + (0 <= t - A[i] ? go(i, t - A[i], m) : INF), go(i + 1, t, m)); // min(1 + with, without)
        }
    public:
        int coinChange(VI& coins, int amount) {
            A = coins;
            N = A.size();
            T = amount;
            VVI m(N + 1, VI(T + 1, -1));
            auto ans = go(0, T, m);
            return ans < INF ? ans : -1;
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int coinChange(VI& A, int T, int INF = int(1e9 + 7)) {
            int N = A.size();
            VVI dp(N + 1, VI(T + 1, INF));
            for (auto i{ 0 }; i <= N; ++i)
                dp[i][0] = 0;
            for (auto i{ 1 }; i <= N; ++i)
                for (auto t{ 1 }; t <= T; ++t)
                    dp[i][t] = min(1 + (0 <= t - A[i - 1] ? dp[i][t - A[i - 1]] : INF), dp[i - 1][t]); // min(1 + with, without)
            return dp[N][T] < INF ? dp[N][T] : -1;
        }
    };
}

namespace BottomUpMemOpt1 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int coinChange(VI& A, int T, int INF = int(1e9 + 7)) {
            int N = A.size();
            VI pre(T + 1, INF),
               cur{ pre };
            for (auto i{ 1 }; i <= N; ++i) {
                cur[0] = 0;
                for (auto t{ 1 }; t <= T; ++t)
                    cur[t] = min(1 + (0 <= t - A[i - 1] ? cur[t - A[i - 1]] : INF), pre[t]); // min(1 + with, without)
                swap(pre, cur);
            }
            return pre[T] < INF ? pre[T] : -1;
        }
    };
}

namespace BottomUpMemOpt2 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int coinChange(VI& A, int T, int INF = int(1e9 + 7)) {
            int N = A.size();
            VI dp(T + 1, INF);
            dp[0] = 0;
            for (auto i{ 1 }; i <= N; ++i)
                for (auto t{ 1 }; t <= T; ++t)
                    dp[t] = min(1 + (0 <= t - A[i - 1] ? dp[t - A[i - 1]] : INF), dp[t]); // min(1 + with, without)
            return dp[T] < INF ? dp[T] : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
