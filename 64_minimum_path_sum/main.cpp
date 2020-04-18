/*
 * 64. Minimum Path Sum
 *
 * Q: https://leetcode.com/problems/minimum-path-sum/
 * A: https://leetcode.com/problems/minimum-path-sum/discuss/585496/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int minPathSum(VVI& A) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            VVI dp(M, VI(N, -1));
            auto ans = go(A, M - 1, N - 1, dp);
            return ans;
        }
    private:
        int go(VVI& A, int i, int j, VVI& dp, int res = -1) {
            if (dp[i][j] > -1)
                return dp[i][j];
            if (!i && !j)
                return A[0][0];
            if (!i) res = A[i][j] + go(A, i, j - 1, dp);
            if (!j) res = A[i][j] + go(A, i - 1, j, dp);
            if (i && j) res = A[i][j] + min(go(A, i, j - 1, dp), go(A, i - 1, j, dp));
            return dp[i][j] = res;
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int minPathSum(VVI& A) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            VVI dp{ A };
            for (auto i{ 1 }; i < M; ++i) dp[i][0] += dp[i - 1][0];
            for (auto j{ 1 }; j < N; ++j) dp[0][j] += dp[0][j - 1];
            for (auto i{ 1 }; i < M; ++i)
                for (auto j{ 1 }; j < N; ++j)
                    dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
            return dp[M - 1][N - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
