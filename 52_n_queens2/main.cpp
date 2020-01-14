/*
 * 52. N-Queens 2
 *
 * Q: https://leetcode.com/problems/n-queens-ii/
 * A: https://leetcode.com/problems/n-queens-ii/discuss/480337/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int totalNQueens(int N, VVI ans = {}, int cnt = 0) {
        VI A(N, -1); // row is index and col is value of each queen
        return dfs(A, ans);
    }
private:
    bool ok(VI& A, int i, int j) {
        if (A[i] > -1 || find(A.begin(), A.end(), j) != A.end())
            return false;
        for (auto row = 0; row < A.size(); ++row) {
            auto col = A[row];
            if (col > -1 && abs(row - i) == abs(col - j))
                return false;
        }
        return true;
    };
    int dfs(VI& A, VVI& ans, int i = 0, int cnt = 0) {
        auto N = A.size();
        if (i == N) {
            ans.push_back(A);
            return 1;
        }
        for (auto j = 0; j < N; ++j) {
            if (!ok(A, i, j))
                continue;
            A[i] = j;
            cnt += dfs(A, ans, i + 1);
            A[i] = -1;
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
