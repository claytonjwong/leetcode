/*
 * 56. Merge Intervals
 *
 * Q: https://leetcode.com/problems/merge-intervals/
 * A: https://leetcode.com/problems/merge-intervals/discuss/940348/Kt-Js-Py3-Cpp-Sort-A-%2B-Track-Overlaps-via-Last-End
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI merge(VVI& A, VVI ans = {}) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        ans.push_back(A[0]);
        for (auto& interval: A) {
            auto [beg, end] = tie(interval[0], interval[1]);
            auto lastIndex = ans.size() - 1;
            auto lastEnd = ans[lastIndex][1];
            if (beg <= lastEnd)
                ans[lastIndex][1] = max(lastEnd, end);  // overlap
            else
                ans.push_back(interval);                // no overlap
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
