/*
 * 673. Number of Longest Increasing Subsequence
 *
 * Q: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
 * A: https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/916696/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findNumberOfLIS(VI& A, int length = 0, int best = 0) {
        int N = A.size();
        VI dp(N, 1),
           cnt(N, 1);
        for (auto j{ 0 }; j < N; ++j) {
            for (auto i{ 0 }; i < j; ++i) {
                if (A[i] < A[j]) {
                    if (dp[j] < 1 + dp[i])
                        dp[j] = 1 + dp[i],
                        cnt[j] = 0;
                    if (dp[j] == 1 + dp[i])
                        cnt[j] += cnt[i];
                }
            }
            if (length < dp[j])
                length = dp[j],
                best = 0;
            if (length == dp[j])
                best += cnt[j];
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
