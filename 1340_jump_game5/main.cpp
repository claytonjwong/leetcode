/*
 * 1340. Jump Game V
 *
 * Q: https://leetcode.com/problems/jump-game-v/
 * A: https://leetcode.com/problems/jump-game-v/discuss/521774/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*

top-down DP with memoization

for each starting index [i..N)
    go(i, L, R, memo)

go(i, L, R, memo) {
    if memo[i]
        return memo[i]

    left = 0
    for the K items to the left of i
        if < A[i], then left = max(left, 1 + go(K-th item to the left))

    right = 0
    for the K items to the right of i
        if < A[i], then right = max(right, 1 + go(K-th item to the right)

    return memo[i] = max(left, right)
}

*/

class Solution {
public:
    using VI = vector<int>;
    using Memo = unordered_map<int, int>;
    int maxJumps(VI& A, int K, Memo m = {}, int ans = 0) {
        for (auto i = 0; i < A.size(); ++i)
            ans = max(ans, go(A, K, m, i));
        return ans;
    }
private:
    int go(VI& A, int K, Memo& m, int i) {
        if (m[i])
            return m[i];
        int L = 0, R = 0, N = A.size();
        for (auto j = i - 1; j >= max(i - K, 0    ) && A[j] < A[i]; --j) L = max(L, 1 + go(A, K, m, j)); // 👈 to-the-(L)eft
        for (auto j = i + 1; j <= min(i + K, N - 1) && A[j] < A[i]; ++j) R = max(R, 1 + go(A, K, m, j)); //    to-the-(R)ight 👉
        return m[i] = max({L, R, 1});
    }
};

int main() {
    Solution solution;
    { Solution::VI A{6,4,14,6,8,13,9,7,10,6,12}; auto K = 2; cout << solution.maxJumps(A, K) << endl; }
    { Solution::VI A{3,3,3,3,3}; auto K = 3; cout << solution.maxJumps(A, K) << endl; }
    { Solution::VI A{7,6,5,4,3,2,1}; auto K = 1; cout << solution.maxJumps(A, K) << endl; }
    { Solution::VI A{2,1,2,1,2,1}; auto K = 2; cout << solution.maxJumps(A, K) << endl; }
    { Solution::VI A{69}; auto K = 2; cout << solution.maxJumps(A, K) << endl; }
    return 0;
}
