/*
 * 200. Number of Islands
 *
 * Q: https://leetcode.com/problems/number-of-islands/
 * A: https://leetcode.com/problems/number-of-islands/discuss/753546/Javascript-Python3-C%2B%2B-DFS-%2B-BFS
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

namespace DFS {
    class Solution {
        using Grid = vector<vector<char>>;
        using Map = unordered_map<int, unordered_map<int, bool>>;
        using Dirs = vector<tuple<int, int>>;
        Grid A;
        int M, N;
        Map seen;
        int go(int i, int j) {
            if (i < 0 || i == M || j < 0 || j == N || A[i][j] == '0' || seen[i][j]) // 🛑 OOB, water, or already seen 👀
                return 0;
            seen[i][j] = true;
            for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) // 🚀 DFS explore adj u,v [👆, 👉, 👇, 👈]
                go(u, v);
            return 1;
        }
    public:
        int numIslands(Grid& A_, int cnt = 0) {
            A = A_;
            M = A.size();
            N = M ? A[0].size() : 0;
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    cnt += go(i, j);
            return cnt;
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using Grid = vector<vector<char>>;
        using Map = unordered_map<int, unordered_map<int, bool>>;
        using Pair = pair<int, int>;
        using Dirs = vector<Pair>;
        using Queue = queue<Pair>;
        int numIslands(Grid& A, Map seen = {}, int cnt = 0) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            auto bfs = [&](auto row, auto col) {
                if (A[row][col] == '0' || seen[row][col])
                    return 0;
                seen[row][col] = true;
                Queue q{{{ row, col }}};
                while (q.size()) {
                    auto [i, j] = q.front(); q.pop();
                    for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) // 🚌 BFS explore adj u,v [👆, 👉, 👇, 👈]
                        if (!(u < 0 || u == M || v < 0 || v == N || A[u][v] == '0' || seen[u][v])) // if *not* OOB, water, or already seen 👀
                            q.push({ u, v }), seen[u][v] = true;
                }
                return 1;
            };
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    cnt += bfs(i, j);
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
