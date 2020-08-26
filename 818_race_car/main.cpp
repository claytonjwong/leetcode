/*
 * 818. Race Car
 *
 * Q: https://leetcode.com/problems/race-car/
 * A: https://leetcode.com/problems/race-car/discuss/124312/Javascript-Python3-C%2B%2B-.-BFS-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    using Pair = pair<int, int>;
    using Pairs = vector<Pair>;
    using Queue = queue<Pair>;
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    int racecar(int T, Seen seen = {}, int depth = 0) {
        Queue q{{{ 0, 1 }}};
        seen[0][1] = true;
        for (;;) {
            int k = q.size();
            while (k--) {
                auto [pos, vel] = q.front(); q.pop();
                if (pos == T)
                    return depth;  // 🎯 target T found
                Pairs cand;
                if (abs(T - (pos + vel)) < T)
                    cand.push_back({ pos + vel, 2 * vel });
                cand.push_back({ pos, vel < 0 ? 1 : -1 });
                for (auto [pos, vel]: cand)
                    if (!seen[pos][vel])
                        q.push({ pos, vel }), seen[pos][vel] = true;
            }
            ++depth;
        }
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
