/*
 * 300. Longest Increasing Subsequence
 *
 * Q: https://leetcode.com/problems/longest-increasing-subsequence/
 * A: https://leetcode.com/problems/longest-increasing-subsequence/discuss/385203/C%2B%2B-and-Javascript-solutions
 */

/*

 A = 10 9 2 5 3 4
      0 1 2 3 4 5 6
      j           => 1
      i j         => 1
      i i j       => 1
      i i i j     => 2
      i i i i j   => 2
      i i i i i j => 3

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int lengthOfLIS(VI& A, int max = 1) {
        int N = A.size();
        if (N == 0)
            return 0;
        VI dp(N, 1);
        for (auto j{ 1 }; j < N; ++j)
            for (auto i{ 0 }; i < j; ++i)
                if (A[i] < A[j])
                    max = std::max(max, dp[j] = std::max(dp[j], 1 + dp[i]));
        return max;
    }
};

int main() {
    Solution solution;
    Solution::VI A{10, 9, 2, 5, 3, 4};
    cout << solution.lengthOfLIS(A) << endl;
    return 0;
}
