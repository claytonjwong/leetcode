/*
 * 1260. Shift 2D Grid
 *
 * Q: https://leetcode.com/problems/shift-2d-grid/
 * A: https://leetcode.com/problems/shift-2d-grid/discuss/432317/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI shiftGrid(VVI& A, int k, VI seq={}) {
        int M = A.size(),
            N = A[0].size();
        k %= (M * N);
        if (k == 0)
            return A;
        for (auto i=0; i < M; ++i)
            for (auto j=0; j < N; ++j)
                seq.push_back(A[i][j]);
        auto pivot = seq.begin() + (M * N) - k;
        VI shifted{pivot, seq.end()};
        shifted.insert(shifted.end(), seq.begin(), pivot);
        VVI ans(M, VI(N));
        for (auto i=0; i < M * N; ++i)
            ans[i / N][i % N] = shifted[i];
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,2},{3,4}};
    auto k = 1;
    auto ans = solution.shiftGrid(A, k);
    for (auto row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, "")), cout << endl;
    return 0;
}