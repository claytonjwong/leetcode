/*
 * 1301. Number of Paths with Max Score
 *
 * Q: https://leetcode.com/problems/number-of-paths-with-max-score/
 * A: https://leetcode.com/problems/number-of-paths-with-max-score/discuss/483085/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Top-Down TLE without Memo
/*
class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    using Map = unordered_map<int, int>;
    VI pathsWithMaxScore(VS& A, Map paths = {}, int best = 0) {
        int M = A.size(), N = A[0].size();
        go(A, M - 1, N - 1, paths, best);
        if (paths.empty())
            return {0, 0};
        return {best, paths[best]};
    }
private:
    void go(VS& A, int i, int j, Map& paths, int& best, int sum = 0) {
        if (i == 0 && j == 0) {
            if (best <= sum) {
                best = sum;
                ++paths[best];
            }
            return;
        }
        sum += A[i][j] != 'S' ? A[i][j] - 48 : 0;
        if (i - 1 >= 0 && A[i - 1][j] != 'X') go(A, i - 1, j, paths, best, sum);
        if (j - 1 >= 0 && A[i][j - 1] != 'X') go(A, i, j - 1, paths, best, sum);
        if (i - 1 >= 0 && j - 1 >= 0 && A[i - 1][j - 1] != 'X') go(A, i - 1, j - 1, paths, best, sum);
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VS = vector<string>;
    VI pathsWithMaxScore(VS& A, VVI dirs = VVI{{-1,-1},{-1,0},{0,-1}}, int mod = 1e9 + 7) {
        auto N = A.size();
        VVI S(N + 1, VI(N + 1)),
            P(N + 1, VI(N + 1));
        A[0][0] = A[N - 1][N - 1] = '0';
        P[0][0] = 1;
        for (auto i = 1; i <= N; ++i) {
            for (auto j = 1; j <= N; ++j) {
                if (A[i - 1][j - 1] == 'X')
                    continue;
                for (auto& d: dirs) {
                    auto u = i + d[0],
                         v = j + d[1];
                    auto sum = S[u][v] + (A[i - 1][j - 1] - '0');
                    if (sum == S[i][j])
                        P[i][j] = (P[i][j] + P[u][v]) % mod; // add path to existing best score
                    if (S[i][j] < sum)
                        S[i][j] = sum,
                        P[i][j] = P[u][v]; // reset path to new best score
                }
            }
        }
        return {S[N][N], P[N][N]};
    }
};

int main() {
    Solution solution;
    Solution::VS A{"E11","XXX","11S"};
    auto ans = solution.pathsWithMaxScore(A);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
