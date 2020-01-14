/*
 * 1314. Matrix Block Sum
 *
 * Q: https://leetcode.com/problems/matrix-block-sum/
 * A:
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI matrixBlockSum(VVI& A, int K) {
        int M = A.size(), N = A[0].size();
        auto sum = [&](auto i, auto j) {
            int res = 0;
            for (auto r = max(i - K, 0); r < min(i + K + 1, M); ++r)
                for (auto c = max(j - K, 0); c < min(j + K + 1, N); ++c)
                    res += A[r][c];
            return res;
        };
        VVI ans(M, VI(N));
        for (auto i = 0; i < M; ++i)
            for (auto j = 0; j < N; ++j)
                ans[i][j] = sum(i, j);
        return ans;
    }
};

int main() {
    Solution solution;
    {
        Solution::VVI A{{1,2,3},{4,5,6},{7,8,9}};
        auto K = 1;
        auto ans = solution.matrixBlockSum(A, K);
        for (auto& row: ans)
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    }
    {
        Solution::VVI A{{1,2,3},{4,5,6},{7,8,9}};
        auto K = 2;
        auto ans = solution.matrixBlockSum(A, K);
        for (auto& row: ans)
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    }
    return 0;
}
