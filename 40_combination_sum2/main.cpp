/*
 * 40. Combination Sum II
 *
 * Q: https://leetcode.com/problems/combination-sum-ii/
 * A: https://leetcode.com/problems/combination-sum-ii/discuss/506360/Javascript-Python3-C%2B%2B-DFS-%2B-BT-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<VVI(int, int, VI&&)>;
    using Set = unordered_set<string>;
    VVI combinationSum2(VI& A, int T, Set seen = {}, VVI paths = {}) {
        auto hash = [](auto path) {
            stringstream ss;
            sort(path.begin(), path.end());
            copy(path.begin(), path.end(), ostream_iterator<int>(ss, ","));
            return ss.str();
        };
        fun go = [&](int start, int t, VI&& path = {}) -> VVI {
            if (!t) {
                auto key = hash(path);
                if (seen.insert(key).second)
                    paths.emplace_back(VI{ path.begin(), path.end() });  // 🎯 unique path with target sum T
                return {};
            }
            for (auto i{ start }; i < A.size(); ++i)
                if (0 <= t - A[i])
                    path.push_back(A[i]),             // 👀 ✅ forward-tracking
                    go(i + 1, t - A[i], move(path)),  // 🚀 recursively explore path with implicit 👀 forward/back-tracking
                    path.pop_back();                  // 👀 🚫 back-tracking
            return paths;
        };
        return go(0, T, {});
    }
};

int main() {
    Solution solution;
    Solution::VI A{2,5,2,1,2};
    auto target = 5;
    auto ans = solution.combinationSum2(A, target);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
