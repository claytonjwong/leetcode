/*
 * 1266. Minimum Time Visiting All Points
 *
 * Q: https://leetcode.com/problems/minimum-time-visiting-all-points/
 * A: https://leetcode.com/problems/minimum-time-visiting-all-points/discuss/436603/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int minTimeToVisitAllPoints(VVI& A, int step=0) {
        int N = A.size();
        auto [x, y] = tie(A[0][0], A[0][1]);
        for (auto i=1; i < N; ++i) {
            auto [next_x, next_y] = tie(A[i][0], A[i][1]);
            for (;;) {
                auto ok = true;
                if (x != next_x) x = x < next_x ? x+1 : x-1, ok = false;
                if (y != next_y) y = y < next_y ? y+1 : y-1, ok = false;
                if (ok)
                    break;
                ++step;
            }
        }
        return step;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,1},{3,4},{-1,0}};
    auto ans = solution.minTimeToVisitAllPoints(A);
    cout << ans << endl;
    return 0;
}