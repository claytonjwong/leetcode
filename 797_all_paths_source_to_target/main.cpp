/*
 * 797. All Paths From Source to Target
 *
 * Q: https://leetcode.com/problems/all-paths-from-source-to-target/
 * A: https://leetcode.com/problems/all-paths-from-source-to-target/discuss/752917/Kt-Js-Py3-Cpp-DFS-%2B-BT
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using fun = function<void(VI&&)>;
    VVI allPathsSourceTarget(VVI& A, VVI paths = {}) {
        auto N = int(A.size()),
             s = 0,
             t = N - 1;
        fun go = [&](VI&& path) {
            auto u = path.back();
            if (u == t)
                paths.emplace_back(path);  // 🎯 target t reached
            else
                for (auto v: A[u])
                    path.push_back(v),     // ✅ 👀 forward-tracking
                    go(move(path)),        // 🚀 explore edge u -> v
                    path.pop_back();       // 🚫 👀 back-tracking
        };
        go({0});
        return paths;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
