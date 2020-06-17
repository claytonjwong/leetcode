/*
 * 130. Surrounded Regions
 *
 * Q: https://leetcode.com/problems/surrounded-regions/
 * A: https://leetcode.com/problems/surrounded-regions/discuss/692095/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

namespace DFS {
    class Solution {
        using VC = vector<char>;
        using VVC = vector<VC>;
        using Adj = vector<tuple<int, int>>;
        using Map = unordered_map<int, unordered_map<int, bool>>;
        VVC A;
        int M, N;
        void go(int i, int j, Map&& seen = {}) {
            A[i][j] = 'b';
            seen[i][j] = true;
            for (auto [u, v]: Adj{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                if (0 <= u && u < M && 0 <= v && v < N && A[u][v] == 'O' && !seen[u][v])
                    go(u, v, move(seen)); // border cell 🎯
        }
    public:
        void solve(VVC& A_) {
            A = A_;
            M = A.size();
            N = M ? A[0].size() : 0;
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (A[i][j] == 'O' && (!i || !j || i == M - 1 || j == N - 1))
                        go(i, j); // border cell 🎯
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    A[i][j] = A[i][j] == 'b' ? 'O' : 'X'; // set border cells: 'b' 👉 'O'
            A_ = A;
        }
    };
}

namespace BFS {
    class Solution {
    public:
        using VC = vector<char>;
        using VVC = vector<VC>;
        using Adj = vector<tuple<int, int>>;
        using Queue = queue<tuple<int, int>>;
        using Map = unordered_map<int, unordered_map<int, bool>>;
        void solve(VVC& A, Queue q = {}, Map seen = {}) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            auto queueBorderCell = [&](auto i, auto j) {
                A[i][j] = 'b';
                q.push({i, j});
                seen[i][j] = true;
            };
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (A[i][j] == 'O' && (!i || !j || i == M - 1 || j == N - 1))
                        queueBorderCell(i, j); // border cell 🎯
            while (!q.empty()) {
                auto [i, j] = q.front(); q.pop();
                for (auto [u, v]: Adj{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                    if (0 <= u && u < M && 0 <= v && v < N && A[u][v] == 'O')
                        queueBorderCell(u, v); // border cell 🎯
            }
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    A[i][j] = A[i][j] == 'b' ? 'O' : 'X'; // set border cells: 'b' 👉 'O'
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
