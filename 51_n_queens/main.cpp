/*
 * 51. N-Queens
 *
 * Q: https://leetcode.com/problems/n-queens/
 * A: https://leetcode.com/problems/n-queens/discuss/480335/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VVS = vector<VS>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVS solveNQueens(int N, VVI ans = {}, VVS out = {}) {
        VI A(N, -1); // row is index and col is value of each queen
        dfs(A, ans);
        for (auto& x: ans) {
            VS S;
            for (auto j: x) {
                string str(N, '.');
                str[j] = 'Q';
                S.emplace_back(str);
            }
            out.emplace_back(S);
        }
        return out;
    }
private:
    bool ok (VI& A, int i, int j) {
        if (A[i] > -1 || find(A.begin(), A.end(), j) != A.end())
            return false;
        for (auto row = 0; row < A.size(); ++row) {
            auto col = A[row];
            if (col > -1 && abs(row - i) == abs(col - j))
                return false;
        }
        return true;
    };
    void dfs(VI& A, VVI& ans, int i = 0) {
        auto N = A.size();
        if (i == N) {
            ans.push_back(A);
            return;
        }
        for (auto j = 0; j < N; ++j) {
            if (!ok(A, i, j))
                continue;
            A[i] = j;
            dfs(A, ans, i + 1);
            A[i] = -1;
        }
    }
};

int main() {
    Solution solution;
    auto ans = solution.solveNQueens(4);
    for (auto& x: ans) {
        for (auto &row: x)
            copy(row.begin(), row.end(), ostream_iterator<char>(cout, " ")), cout << endl;
        cout << endl;
    }
    return 0;
}
