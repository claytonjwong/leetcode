#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
 * 200. Number of Islands
 *
 * Q: https://leetcode.com/problems/number-of-islands/
 * A: https://leetcode.com/problems/number-of-islands/discuss/528817/Javascript-and-C%2B%2B-solutions
 */


// class Solution {
// public:
//     using Grid = vector<vector<char>>;
//     using Seen = unordered_map<int, unordered_map<int, bool>>;
//     using Dirs = vector<tuple<int, int>>;
//     int numIslands(Grid& A, int color = 0) {
//         auto M = A.size(),
//              N = M == 0 ? 0 : A[0].size();
//         for (auto i = 0; i < M; ++i)
//             for (auto j = 0; j < N; ++j)
//                 if (A[i][j] == '1')
//                     ++color, go(A, color, i, j);
//         return color;
//     }
// private:
//     Dirs dirs = {{-1,0},{0,1},{1,0},{0,-1}};
//     void go(Grid& A, int color, int i, int j, Seen&& seen = {}) {
//         auto M = A.size(),
//              N = M == 0 ? 0 : A[0].size();
//         if (i < 0 || i >= M || j < 0 || j >= N || A[i][j] != '1' || seen[i][j])
//             return;
//         A[i][j] += color;
//         seen[i][j] = true;
//         for (auto [u, v]: dirs)
//             go(A, color, i + u, j + v, move(seen));
//     }
// };

class Solution {
public:
    using Grid = vector<vector<char>>;
    int numIslands(Grid& A, int color = 0) {
        auto M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        for (auto i = 0; i < M; ++i)
            for (auto j = 0; j < N; ++j)
                if (A[i][j] == '1')
                    ++color, bfs(A, color, i, j);
        return color;
    }
private:
    using Seen = unordered_map<int, unordered_map<int, bool>>;
    vector<vector<int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};
    void bfs(Grid& A, int color, int i, int j, Seen seen = {}) {
        auto M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        queue<tuple<int, int>> q{{{i, j}}};
        seen[i][j] = true;
        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            A[i][j] += color;
            for (auto& dir: dirs) {
                int u = i + dir[0],
                        v = j + dir[1];
                if (u < 0 || u >= M || v < 0 || v >= N || A[u][v] != '1' || seen[u][v])
                    continue;
                q.push({u, v});
                seen[u][v] = true;
            }
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
