/*
 * 59. Spiral Matrix II
 *
 * Q: https://leetcode.com/problems/spiral-matrix-ii/
 * A: https://leetcode.com/problems/spiral-matrix-ii/discuss/430457/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI generateMatrix(int N, VVI dirs={{-1,0},{0,1},{1,0},{0,-1}}, int dir=2) { // clockwise relative directions (up, right, down, left)
        VVI ans(N, VI(N));
        generate(ans[0].begin(), ans[0].end(), [i = 0]() mutable { return ++i; }); // first row
        auto row = 0, col = N - 1; // top-right corner
        auto step = N;
        auto run = [&]() {
            row += dirs[dir][0];
            col += dirs[dir][1];
            ans[row][col] = ++step;
        };
        while (--N)
            for (auto i=2; i--; dir = (dir + 1) % 4)
                for (auto n=N; n--; run());
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.generateMatrix(1);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, "")), cout << endl;

    return 0;
}
