/*
 * 62. Unique Paths
 *
 * Q: https://leetcode.com/problems/unique-paths/
 * A: https://leetcode.com/problems/unique-paths/discuss/22965/c-top-down-recursion-and-bottom-up-dp/501132
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using LL = long long;
        using Memo = unordered_map<int, unordered_map<int, LL>>;
        int uniquePaths(int M, int N, Memo memo = {}) {
            memo[0][0] = 1;
            go(M, N, memo);
            return memo[M - 1][N - 1];
        }
    private:
        LL go(int i, int j, Memo& m) {
            if (m[i][j])
                return m[i][j];
            if (i == 0 || j == 0)
                return m[i][j] = 1;
            return m[i][j] = go(i - 1, j, m) + go(i, j - 1, m);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI= vector<int>;
        using VVI = vector<VI>;
        int uniquePaths(int M, int N) {
            VVI dp(M, VI(N, 1));
            for (auto i{ 1 }; i < M; ++i)
                for (auto j{ 1 }; j < N; ++j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            return dp[M - 1][N - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
