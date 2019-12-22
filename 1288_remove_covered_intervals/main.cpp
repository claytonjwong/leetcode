/*
 * 1288. Remove Covered Intervals
 *
 * Q: https://leetcode.com/problems/remove-covered-intervals/
 * A: https://leetcode.com/problems/remove-covered-intervals/discuss/457523/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <vector>

using namespace std;

/*

since the interval length is <= 1000, then *maybe* a quadradic solution will *not* TLE,
but i think i'll first try to code a O(nlogn) solution by sorting the intervals
by their first value, then iterate through the sorted intervals and track the maximum ending value,
if an interval's second value is <= the maximum ending value, then that interval is covered and thus removed.

*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int removeCoveredIntervals(VVI& A, int max = 0, int cnt = 0) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return a[0] < b[0];
        });
        for (auto i = 0; i < A.size(); ++i) {
            auto [beg, end] = tie(A[i][0], A[i][1]);
            if (end <= max)
                continue; // covered
            ++cnt;
            max = end;
        }
        return cnt;
    }
};
*/

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int removeCoveredIntervals(VVI& A, int max = 0, int cnt = 0) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        for (auto i = 0; i < A.size(); ++i)
            if (A[i][1] > max)
                max = A[i][1], ++cnt;
        return cnt;
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int removeCoveredIntervals(VVI& A, int max = 0, int cnt = 0) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        return count_if(A.begin(), A.end(), [&](auto& x) {
            if (x[1] <= max)
                return false;
            max = x[1];
            return true;
        });
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{1,4}, {3,6}, {2,8}};
    cout << solution.removeCoveredIntervals(A) << endl;
    return 0;
}
