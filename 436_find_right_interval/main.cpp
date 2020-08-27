/*
 * 436. Find Right Interval
 *
 * Q: https://leetcode.com/problems/find-right-interval/
 * A: https://leetcode.com/problems/find-right-interval/discuss/814963/Javascript-Python3-C%2B%2B-Lower-Bound
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int, int>;
    VI findRightInterval(VVI& A, Map m = {}, VI ans = {}) {
        int N = A.size();
        for (auto k{ 0 }; k < N; ++k) {
            auto [i, j] = tie(A[k][0], A[k][1]);
            m[i] = k;
        }
        for (auto k{ 0 }; k < N; ++k) {
            auto [i, j] = tie(A[k][0], A[k][1]);
            auto it = m.lower_bound(j);
            ans.push_back(it != m.end() ? it->second : -1);
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
