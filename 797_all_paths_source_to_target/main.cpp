/*
 * 797. All Paths From Source to Target
 *
 * Q: https://leetcode.com/problems/all-paths-from-source-to-target/
 * A: https://leetcode.com/problems/all-paths-from-source-to-target/discuss/752917/Javascript-Python3-C%2B%2B-DFS-%2B-BT
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
    int N, s, t;
    VVI adj, paths;
    void go(int u, VI&& path = {}) {
        if (u == t)
            paths.emplace_back(path); // 🎯 target t reached
        else
            for (auto v: adj[u])
                path.push_back(v), // ✅ 👀 forward-tracking
                go(v, move(path)), // 🚀 explore edge u -> v
                path.pop_back();   // 🚫 👀 back-tracking
    }
public:
    VVI allPathsSourceTarget(VVI& adj_) {
        adj = adj_;
        N = adj.size();
        s = 0;
        t = N - 1;
        go(s, { s });
        return paths;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
