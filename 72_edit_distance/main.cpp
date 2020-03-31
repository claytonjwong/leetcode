/*
 * 72. Edit Distance
 *
 * Q: https://leetcode.com/problems/edit-distance/
 * A: https://leetcode.com/problems/edit-distance/discuss/479377/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    int minDistance(string A, string B) {
        return go(A, B, A.size(), B.size());
    }
private:
    int go(string& A, string& B, int i, int j) {
        if (i == 0 || j == 0)
            return i + j;
        return min({
            go(A, B, i - 1, j - 1) + int(A[i - 1] != B[j - 1]),
            go(A, B, i - 1, j) + 1,
            go(A, B, i, j - 1) + 1
        });
    }
};
*/

/*
class Solution {
public:
    int minDistance(string A, string B) {
        return go(A, B, A.size(), B.size());
    }
private:
    using Memo = unordered_map<string, int>;
    int go(string& A, string& B, int i, int j, Memo&& memo = {}) {
        stringstream ss; ss << i << "," << j;
        auto key = ss.str();
        if (memo.find(key) != memo.end())
            return memo[key];
        if (i == 0 || j == 0)
            return memo[key] = i + j;
        return memo[key] = min({
            go(A, B, i - 1, j - 1, move(memo)) + int(A[i - 1] != B[j - 1]),
            go(A, B, i - 1, j, move(memo)) + 1,
            go(A, B, i, j - 1, move(memo)) + 1
        });
    }
};
*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int minDistance(string A, string B) {
        auto [M, N] = make_tuple(A.size(), B.size());
        VVI dp(M + 1, VI(N + 1));
        for (auto i = 0; i <= M; ++i) dp[i][0] = i;
        for (auto j = 0; j <= N; ++j) dp[0][j] = j;
        for (auto i = 1; i <= M; ++i)
            for (auto j = 1; j <= N; ++j)
                dp[i][j] = min({
                    dp[i - 1][j - 1] + int(A[i - 1] != B[j - 1]),
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1,
                });
        return dp[M][N];
    }
};
*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int minDistance(string A, string B) {
        auto [M, N] = make_tuple(A.size(), B.size());
        VI pre(N + 1), cur(N + 1);
        iota(pre.begin(), pre.end(), 0);
        for (auto i = 1; i <= M; ++i) {
            cur[0] = i;
            for (auto j = 1; j <= N; ++j) {
                cur[j] = min({
                    pre[j - 1] + int(A[i - 1] != B[j - 1]),
                    pre[j] + 1,
                    cur[j - 1] + 1
                });
            }
            swap(pre, cur);
        }
        return pre[N];
    }
};
*/

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
