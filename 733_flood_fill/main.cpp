/*
 * 733. Flood Fill
 *
 * Q: https://leetcode.com/problems/flood-fill/
 * A: https://leetcode.com/problems/flood-fill/discuss/626668/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

namespace DFS {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VVI floodFill(VVI& A, int row, int col, int cur) {
            auto pre = A[row][col];
            return go(A, row, col, pre, cur);
        }
    private:
        using Seen = unordered_map<int, unordered_map<int, bool>>;
        VVI go(VVI& A, int i, int j, int pre, int cur, Seen&& seen = {}) {
            auto M = A.size(),
                 N = M ? A[0].size() : 0;
            if (i < 0 || i == M || j < 0 || j == N || A[i][j] != pre || seen[i][j])
                return {};
            seen[i][j] = true;
            A[i][j] = cur;
            for (auto& dir: VVI{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) { // clockwise [👆, 👉, 👇, 👈]
                auto u = i + dir[0],
                     v = j + dir[1];
                go(A, u, v, pre, cur, move(seen));
            }
            return A;
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Queue = queue<tuple<int, int>>;
        using Seen = unordered_map<int, unordered_map<int, bool>>;
        VVI floodFill(VVI& A, int row, int col, int cur, Queue q = {}, Seen seen = {}) {
            auto M = A.size(),
                 N = M ? A[0].size() : 0;
            auto pre = A[row][col];
            q.push({row, col});
            while (!q.empty()) {
                auto [i, j] = q.front(); q.pop();
                seen[i][j] = true;
                A[i][j] = cur;
                for (auto& dir: VVI{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) { // clockwise [👆, 👉, 👇, 👈]
                    auto u = i + dir[0],
                         v = j + dir[1];
                    if (u < 0 || u == M || v < 0 || v == N || A[u][v] != pre || seen[u][v])
                        continue;
                    q.push({u, v});
                }
            }
            return A;
        }
    };
}

int main() {
    DFS::Solution solution;
    DFS::Solution::VVI A{{1,1,1},{1,1,0},{1,0,1}};
    solution.floodFill(A, 1, 1, 2);
    for (auto& row: A)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
