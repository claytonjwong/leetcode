/*
 * Weekly Contest 169
 * Dec 29, 2019 at 3:55 AM
 * 1 h 30 m	12/19	0:34:58	3/4	1093/4366
 *
 * Q1: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
 * A1: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/discuss/464406/Javascript-and-C%2B%2B-solutions
 *
 * Q2: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
 * A2: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/464415/Javascript-and-C%2B%2B-solutions
 *
 * Q3: https://leetcode.com/problems/jump-game-iii/
 * A3: https://leetcode.com/problems/jump-game-iii/discuss/464420/Javascript-and-C%2B%2B-solutions
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Seen = unordered_set<int>;
    using Queue = queue<int>;
    bool canReach(VI& A, int i) {
        auto ok = [&](auto x) { return 0 <= x && x < A.size(); };
        Queue q{{i}}; Seen seen{i};
        while (!q.empty()) {
            auto x = q.front(); q.pop();
            if (A[x] == 0)
                return true;
            auto [l, r] = make_tuple(x + A[x], x - A[x]);
            if (ok(l) && seen.insert(l).second)
                q.push(l);
            if (ok(r) && seen.insert(r).second)
                q.push(r);
        }
        return false;
    }
};

int main() {
    Solution solution;
    Solution::VI A{4,2,3,0,3,1,2}; auto i = 5;
    auto ans = solution.canReach(A, i);
    cout << ans << endl;
    return 0;
}
