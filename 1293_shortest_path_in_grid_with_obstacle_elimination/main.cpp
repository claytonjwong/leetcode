/*
 * 1293. Shortest Path in a Grid with Obstacles Elimination
 *
 * Q: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
 * A: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/484985/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

/*
// TLE
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int shortestPath(VVI& A, int T, int ans = 1e9 + 7) {
        dfs(A, T, ans);
        return ans < 1e9 + 7 ? ans : -1;
    }
private:
    VVI dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    using Seen = unordered_set<string>;
    void dfs(VVI& A, int T, int& ans, int i = 0, int j = 0, int k = 0, int steps = 0, Seen&& seen = {"0,0,0"}) {
        int M = A.size(),
            N = A[0].size();
        if (i == M - 1 && j == N - 1) {
            if (ans > steps)
                ans = steps;
            return;
        }
        for (auto& d: dirs) {
            auto u = i + d[0],
                 v = j + d[1];
            if (!(0 <= u && u < M && 0 <= v && v < N))
                continue;
            auto w = k + A[u][v];
            if (w > T)
                continue;
            stringstream key; key << u << "," << v << "," << w;
            if (seen.find(key.str()) != seen.end())
                continue;
            seen.insert(key.str());
            dfs(A, T, ans, u, v, w, steps + 1, move(seen));
        }
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    using Seen = unordered_set<string>;
    using Queue = queue<tuple<int,int,int,int>>;
    int shortestPath(VVI& A, int T) {
        int M = A.size(),
                N = A[0].size();
        Queue q{{{0, 0, 0, 0}}}; // i, j, k, steps
        Seen seen{"0,0,0"};
        while (!q.empty()) {
            auto [i, j, k, steps] = q.front(); q.pop();
            if (i == M - 1 && j == N - 1)
                return steps;
            for (auto& d: dirs) {
                auto u = i + d[0],
                     v = j + d[1];
                if (!(0 <= u && u < M && 0 <= v && v < N))
                    continue;
                auto w = k + A[u][v];
                if (w > T)
                    continue;
                stringstream key; key << u << "," << v << "," << w;
                if (seen.find(key.str()) != seen.end())
                    continue;
                seen.insert(key.str());
                q.push({u, v, w, steps + 1});
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{{0,0,0},
                    {1,1,0},
                    {0,0,0},
                    {0,1,1},
                    {0,0,0}};
    int T = 1;
    cout << solution.shortestPath(A, T) << endl;
    return 0;
}
