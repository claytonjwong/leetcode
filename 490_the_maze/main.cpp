/*
 * 490. The Maze
 *
 * Q: https://leetcode.com/problems/the-maze/
 * A: https://leetcode.com/problems/the-maze/discuss/806498/Javascript-Python3-C%2B%2B-DFS-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Dirs = vector<tuple<int, int>>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    using fun = function<bool(int,int)>;
    bool hasPath(VVI& A, VI& start, VI& target, Seen seen = {}) {
        auto M = A.size(),
             N = M ? A[0].size() : 0;
        fun go = [&](auto i, auto j) {
            if (i == target[0] && j == target[1])  // 🎯 target
                return true;
            for (auto [row, col]: Dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {  // [👆, 👉, 👇, 👈 ]
                auto u{ i },
                     v{ j };
                // 1. 🚌 continue in same direction until 💥 collision
                while (0 <= u && u < M && 0 <= v && v < N && !A[u][v])
                    u += col,
                    v += row;
                // 2. 🚀 recursively explore previous position proceeding 💥 collision
                u -= col;
                v -= row;
                if (seen[u][v])
                    continue;
                seen[u][v] = true;
                if (go(u, v))
                    return true;
            }
            return false;
        };
        return go(start[0], start[1]);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
