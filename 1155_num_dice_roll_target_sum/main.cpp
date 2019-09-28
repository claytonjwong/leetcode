#include <iostream>
#include <vector>

using namespace std;

/*

 top-down solution:

 given d dice and t target, assume we know the optimal solution given one less die ( ie. d' = d - 1 ).  Let t' denote
 the value of the remaining target minus the optimal value of the one less die.  The optimal solution then for d and t can be
 recursively derived from d' and t' per the following recurrence relation:

 the optimal solution for d dice and t target is equal to the optimal value for some current arbitrary i-th die plus
 the optimal solution for d' dice and t' target.

 Note: to find the optimal value for the current arbitrary i-th die, simple iterate through and try each value of 1..f inclusive.

 Note: the solution without memoization results in TLE, since overlapping sub-problems are solved repeatedly.

 */

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int numRollsToTarget(int d, int f, int t, int ans=0) {
        if (d == 0)
            return static_cast<int>(t == 0);
        for (auto i=1; i <= f; ++i)
            if (t-i >= 0)
                ans = (ans + numRollsToTarget(d-1, f, t-i)) % static_cast<int>(1e9+7);
        return ans;
    }
};
*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int numRollsToTarget(int d, int f, int t, VVI&& memo=VVI(31, VI(1001, -1)), int ans=0) {
        if (memo[d][t] > -1)
            return memo[d][t];
        if (d == 0)
            return memo[d][t] = static_cast<int>(t == 0);
        for (auto i=1; i <= f; ++i)
            if (t-i >= 0)
                ans = (ans + numRollsToTarget(d-1, f, t-i, move(memo))) % static_cast<int>(1e9+7);
        return memo[d][t] = ans;
    }
};
*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int numRollsToTarget(int d, int f, int t) {
        VVI dp(d+1, VI(t+1));
        dp[0][0] = 1;
        for (auto i=1; i <= d; ++i)
            for (auto j=1; j <= t; ++j)
                for (auto k=1; k <= f; ++k)
                    if (j-k >= 0)
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % static_cast<int>(1e9+7);
        return dp[d][t];
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    int numRollsToTarget(int d, int f, int t) {
        VI pre(t+1), cur(t+1);
        cur[0] = 1;
        for (auto i=1; i <= d; ++i) {
            swap(pre, cur);
            fill(cur.begin(), cur.end(), 0);
            for (auto j=1; j <= t; ++j)
                for (auto k=1; k <= f; ++k)
                    if (j-k < 0)
                        break;
                    else
                        cur[j] = (cur[j] + pre[j-k]) % static_cast<int>(1e9+7);
        }
        return cur[t];
    }
};

int main() {
    Solution solution;
    cout << solution.numRollsToTarget(1, 6, 3) << endl;
    cout << solution.numRollsToTarget(2, 6, 7) << endl;
    cout << solution.numRollsToTarget(2, 5, 10) << endl;
    cout << solution.numRollsToTarget(1, 2, 3) << endl;
    cout << solution.numRollsToTarget(30, 30, 500) << endl;
    return 0;
}