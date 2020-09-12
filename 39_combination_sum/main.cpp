/*
 * 39. Combination Sum
 *
 * Q: https://leetcode.com/problems/combination-sum/
 * A: https://leetcode.com/problems/combination-sum/discuss/506331/Javascript-Python3-C%2B%2B-DFS-%2B-BT-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<VVI(int, int, VI&&)>;
    VVI combinationSum(VI& A, int T, VVI paths = {}) {
        fun go = [&](int start, int t, VI&& path = {}) -> VVI {
            if (!t) {
                paths.emplace_back(path);         // 🎯 unique path with target sum T
                return {};
            }
            for (auto i{ start }; i < A.size(); ++i)
                if (0 <= t - A[i])
                    path.push_back(A[i]),         // 👀 ✅ forward-tracking
                    go(i, t - A[i], move(path)),  // 🚀 recursively explore path
                    path.pop_back();              // 👀 🚫 back-tracking
            return paths;
        };
        return go(0, T, {});
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
