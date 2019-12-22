/*
 * 1287. Element Appearing More Than 25% In Sorted Array
 *
 * Q: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
 * A: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/discuss/453406/Javascript-and-C%2B%2B-solutions
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Counter = unordered_map<int, int>;
    int findSpecialInteger(VI& A, Counter cnt = {}) {
        for (auto x: A)
            if (++cnt[x] > A.size() / 4.0)
                return x;
        return -1;
    }
};

/*
class Solution {
public:
    using VI = vector<int>;
    using Counter = unordered_map<int, int>;
    int findSpecialInteger(VI& A, Counter cnt = {}) {
        return *find_if(A.begin(), A.end(), [&](auto x) { return ++cnt[x] > A.size() / 4.0; });
    }
};
*/

int main() {
    Solution solution;
    Solution::VI A{1,2,3,3};
    auto ans = solution.findSpecialInteger(A);
    cout << ans << endl;
    return 0;
}
