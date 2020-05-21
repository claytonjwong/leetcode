/*
 * 1277. Count Square Submatrices with All Ones
 *
 * Q: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 * A: https://leetcode.com/problems/count-square-submatrices-with-all-ones/discuss/442151/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int countSquares(VVI& A, int cnt = 0) {
            auto M = A.size(),
                 N = A[0].size();
            VVI dp(M + 1, VI(N + 1));
            for (auto i{ 1 }; i <= M; ++i)
                for (auto j{ 1 }; j <= N; ++j)
                    if (A[i - 1][j - 1])
                        cnt += dp[i][j] = 1 + min({ dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1] });
            return cnt;
        }
    };
}

namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int countSquares(VVI& A, int cnt = 0) {
            auto M = A.size(),
                 N = A[0].size();
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (A[i][j])
                        cnt += A[i][j] = 1 + (i && j ? min({ A[i][j - 1], A[i - 1][j], A[i - 1][j - 1] }) : 0);
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
