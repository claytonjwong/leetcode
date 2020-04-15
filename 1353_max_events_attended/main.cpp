/*
 * 1353. Maximum Number of Events That Can Be Attended
 *
 * Q: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
 * A: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/579912/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VVI = vector<vector<int>>;
    using Set = unordered_set<int>;
    int maxEvents(VVI& A, Set seen = {}) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        for (auto& e: A)
            for (auto [i, j] = tie(e[0], e[1]); i <= j && !seen.insert(i).second; ++i);
        return seen.size();
    }
};

int main() {
    Solution::VVI A{
        {1,5},
        {1,5},
        {1,5},
        {2,3},
        {2,3},
    };
    cout << Solution().maxEvents(A) << endl;
    return 0;
}
