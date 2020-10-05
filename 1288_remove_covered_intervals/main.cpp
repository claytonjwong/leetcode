/*
 * 1288. Remove Covered Intervals
 *
 * Q: https://leetcode.com/problems/remove-covered-intervals/
 * A: https://leetcode.com/problems/remove-covered-intervals/discuss/457523/Javascript-Python3-C%2B%2B-Sort-%2B-Linear-Scan
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int removeCoveredIntervals(VVI& A, int x = 0) {
        sort(A.begin(), A.end(), [](auto& first, auto& second) {
            auto [a, b] = tie(first[0], first[1]);
            auto [c, d] = tie(second[0], second[1]);
            return a == c ? d < b : a < c;
        });
        auto ok = [&](auto& first, auto& second) {
            auto [a, b] = tie(first[0], first[1]);
            auto [c, d] = tie(second[0], second[1]);
            return a <= c && d <= b;
        };
        int N = A.size(),
            i = 0,
            j = 1;
        while (j < N)
            if (ok(A[i], A[j]))
                ++x,
                ++j;
            else
                i = j++;
        return N - x;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,4}, {3,6}, {2,8}};
    cout << solution.removeCoveredIntervals(A) << endl;
    return 0;
}
