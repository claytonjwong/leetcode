/*
 * 1654. Minimum Jumps to Reach Home
 *
 * Q: https://leetcode.com/problems/minimum-jumps-to-reach-home/
 * A: https://leetcode.com/problems/minimum-jumps-to-reach-home/discuss/935386/Kt-Js-Py3-Cpp-BFS-%2B-DFS-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

namespace BFS {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        using Seen = unordered_set<string>;
        using Queue = queue<tuple<int, bool, int>>;
        int minimumJumps(VI& A, int R, int L, int T, Seen seen = {}) {
            Set forbidden{ A.begin(), A.end() };
            auto markSeen = [&](auto i, auto backwards) {
                stringstream key; key << i << "," << backwards;
                return seen.insert(key.str()).second;
            };
            auto ok = [&](auto i, auto backwards) {
                return 0 <= i && i < 4000 && forbidden.find(i) == forbidden.end() && markSeen(i, backwards);
            };
            Queue q{{{ 0, false, 0 }}}; markSeen(0, false);
            while (q.size()) {
                auto [i, backwards, steps] = q.front(); q.pop();
                if (i == T)
                    return steps;
                if (ok(i + R, false))
                    q.push({ i + R, false, steps + 1 });
                if (!backwards && ok(i - L, true))
                    q.push({ i - L, true, steps + 1 });
            }
            return -1;
        }
    };
}
namespace DFS {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        using Seen = unordered_set<string>;
        using fun = function<void(int, int, bool)>;
        static constexpr auto INF = int(1e9 + 7);
        int minimumJumps(VI& A, int R, int L, int T, Seen seen = {}, int best = INF) {
            Set forbidden{ A.begin(), A.end() };
            fun go = [&](auto i, auto steps, auto backwards) {
                if (forbidden.find(i) != forbidden.end())         // 🚫 forbidden
                    return;
                stringstream key; key << i << " " << backwards;
                if (!seen.insert(key.str()).second)               // 👀 seen
                    return;
                if (i == T) {
                    best = min(best, steps);                      // 🎯 minimum steps to reach target
                    return;
                }
                if (i < 0 || 4000 < i)                            // 🛑 out of bounds
                    return;
                go(i + R, steps + 1, false);                      // 🚀 DFS explore 👉 to-the-right
                if (!backwards)
                    go(i - L, steps + 1, true);                   // 🚀 DFS explore 👈 to-the-left
            };
            go(0, 0, false);
            return best < INF ? best : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
