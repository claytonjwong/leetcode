/*
 * 1143. Longest Common Subsequence
 *
 * Q: https://leetcode.com/problems/longest-common-subsequence/
 * A: https://leetcode.com/problems/longest-common-subsequence/discuss/599042/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown_Without_Memo {
    class Solution {
    public:
        int longestCommonSubsequence(string A, string B) {
            return go(A, B, A.size(), B.size());
        }
    private:
        int go(string& A, string& B, int i = 0, int j = 0) {
            if (!i || !j)
                return 0;
            return max({
                go(A, B, i - 1, j - 1) + (A[i - 1] == B[j - 1]), // match?
                go(A, B, i - 1, j), go(A, B, i, j - 1),   // indels
            });
        }
    };
}
namespace TopDown_With_Memo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int longestCommonSubsequence(string A, string B) {
            return go(A, B, A.size(), B.size());
        }
    private:
        int go(string& A, string& B, int i, int j, VVI&& m = VVI(1001, VI(1001, -1))) {
            if (m[i][j] > -1)
                return m[i][j];
            if (!i || !j)
                return m[i][j] = 0;
            return m[i][j] = max({
                go(A, B, i - 1, j - 1, move(m)) + (A[i - 1] == B[j - 1]),        // match?
                go(A, B, i - 1, j, move(m)), go(A, B, i, j - 1, move(m)), // indels
            });
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int longestCommonSubsequence(string A, string B) {
            auto M = A.size(),
                 N = B.size();
            VVI dp(M + 1, VI(N + 1));
            for (auto i{ 1 }; i <= M; ++i)
                for (auto j{ 1 }; j <= N; ++j)
                    dp[i][j] = max({
                        dp[i - 1][j - 1] + (A[i - 1] == B[j - 1]), // match?
                        dp[i - 1][j], dp[i][j - 1],                // indels
                    });
            return dp[M][N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
