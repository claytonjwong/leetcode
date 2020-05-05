/*
 * 463. Island Perimeter
 *
 * Q: https://leetcode.com/problems/island-perimeter/
 * A: https://leetcode.com/problems/island-perimeter/discuss/613726/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int islandPerimeter(VVI& A, int cnt = 0) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            auto adj = [&](auto i, auto j) {
                for (auto& dir: VVI{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
                    auto u = i + dir[0],
                         v = j + dir[1];
                    cnt += (u < 0 || u == M || v < 0 || v == N) ? 1 : !A[u][v];
                }
            };
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (A[i][j])
                        adj(i, j);
            return cnt;
        }
    };
}
namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Dirs = vector<pair<int, int>>;
        int islandPerimeter(VVI& A, int cnt = 0) {
            int M = A.size(),
                N = M ? A[0].size() : 0;
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (A[i][j])
                        for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                            cnt += u < 0 || u == M || v < 0 || v == N || !A[u][v]; // +1 for out-of-bounds xor water 🎯
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
