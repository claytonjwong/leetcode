/*
 * Combination Sum III
 *
 * Q: https://leetcode.com/problems/combination-sum-iii/
 * A: https://leetcode.com/problems/combination-sum-iii/discuss/843173/Javascript-Python3-C%2B%2B-DFS-%2B-BT-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<VVI(int, int, VI&&)>;
    VVI combinationSum3(int N, int T, VVI paths = {}) {
        fun go = [&](auto n, auto t, VI&& path = {}) -> VVI {
            if (!n && !t) {
                paths.emplace_back(VI{ path.begin(), path.end() });  // 🎯 unique path of N nums with T sum
                return {};
            }
            if (!n || !t)
                return {};
            for (auto i = path.size() ? path.back() + 1 : 1; i < 10 && 0 <= t - i; ++i)
                path.push_back(i),             // 👀 ✅ forward-tracking
                go(n - 1, t - i, move(path)),  // 🚀 recursively explore path
                path.pop_back();               // 👀 🚫 back-tracking
            return paths;
        };
        return go(N, T, {});
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
