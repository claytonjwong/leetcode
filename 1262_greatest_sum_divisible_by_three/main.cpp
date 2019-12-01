/*
 * 1262. Greatest Sum Divisible by Three
 *
 * Q: https://leetcode.com/problems/greatest-sum-divisible-by-three/
 * A: https://leetcode.com/problems/greatest-sum-divisible-by-three/discuss/439097/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*

Initially it seems that this is a dp reachability problem.  We can reach each value itself,
and upon those existing reachable numbers, we can add sequentially onto them all the other numbers
to incrementally identify all reachable numbers.  While performing this task, keep track of the maximum sum
evenly divisible by 3.

Problem: this is a N^2 solution, if N is 4 * 10^4, then N^2 is > 10^8, and this solution will TLE!

Question, how can I make this solution more efficient?

This looks like a DP question to me, but instead of tracking all N^2 of the dp table, just track
the last 2 rows, pre/cur (ie. common dp memory optimization).

Let's stick each number into buckets number % 3, (ie. 0, 1, 2) and let's *not* remember each sub-problem solution,
instead just remember and use pre/cur (ie. common dp memory optimization).

*example*
```
nums = [1,2,3,4,4]

dp[0] = 0
dp[1] = 0
dp[2] = 0


nums = [1,2,3,4,4]
        ^
dp[0] = 0
dp[1] = 1
dp[2] = 0
```

 now I see that its only pertinent to store the maximum sum value per mod 3: 0, 1, 2.  As an example, consider an arbitrary
 combination of A's elements whose sum is equal to 10 and some other arbitrary combination of A's elements whose sum
 is equal to 22.  Both 10 and 22 belong to the same mod "bucket" 1 (ie. 10 % 3 == 1 and 22 % 3 = 1).  Now consider the next
 element in A to be the value 8.  Both sums including 8 are evenly divisible by 3 (ie. 10 + 8 == 18 and 22 + 8 == 30),
 however, the maximum sum would be 30.  So it only makes sense to remember the largest sum per mod bucket.

 so i need to memoize the sub-problem solutions per index j per mod bucket

*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maxSumDivThree(VI& A) {
        int N = A.size();
        VVI dp(N+1, VI(3));
        for (auto i=1; i <= N; ++i) {
            auto num = A[i-1];
            for (auto j=0; j < 3; ++j) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                auto sum = num + dp[i-1][j];
                auto k = sum % 3;
                dp[i][k] = max(dp[i][k], sum);
            }
        }
        for (auto& row: dp)
            copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
        return dp[N][0];
    }
};


int main() {
    Solution::VI A{4};
    auto ans = Solution().maxSumDivThree(A);
    cout << ans << endl;
    return 0;
}
