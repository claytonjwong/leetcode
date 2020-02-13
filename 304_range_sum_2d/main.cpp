/*
 * 304. Range Sum Query 2D - Immutable
 *
 * Q: https://leetcode.com/problems/range-sum-query-2d-immutable/
 * A: https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/508260/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    NumMatrix(VVI& A) {
        int M = A.size(),
            N = M ? A[0].size() : 0;
        dp = VVI(M + 1, VI(N + 1));
        for (auto i = 1; i <= M; ++i)
            for (auto j = 1; j <= N; ++j)
                dp[i][j] = A[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
    }

    int sumRegion(int i, int j, int u, int v) {
        return dp[u + 1][v + 1] - dp[i][v + 1] - dp[u + 1][j] + dp[i][j];
    }
private:
    VVI dp;
};

int main() {
    NumMatrix::VVI A{
        {1,1,1},
        {1,1,1},
        {1,1,1},
    };
    NumMatrix m(A);
    cout << m.sumRegion(1,1,2,2) << endl;
    return 0;
}
