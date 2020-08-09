/*
 * 944. Rotting Oranges
 *
 * Q: https://leetcode.com/problems/rotting-oranges/
 * A: https://leetcode.com/problems/rotting-oranges/discuss/782008/Javascript-Python3-C%2B%2B-BFS-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Grid = vector<vector<int>>;
    using Pair = pair<int, int>;
    using Dirs = vector<Pair>;
    using Queue = queue<Pair>;
    using Map = unordered_map<int, unordered_map<int, bool>>;
    int orangesRotting(Grid& A, Queue q = {}, Map seen = {}, int depth = 0, int need = 0) {
        auto M = A.size(),
             N = A[0].size();
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (A[i][j] == 1)
                    ++need;
                else if (A[i][j] == 2)
                    q.push({ i, j }), seen[i][j] = true;
        if (!need)
            return 0;
        while (q.size()) {
            int k = q.size();
            while (k--) {
                auto [i, j] = q.front(); q.pop();
                for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                    if (!(u < 0 || u == M || v < 0 || v == N || seen[u][v]) && A[u][v] == 1)
                        --need, q.push({ u, v }), seen[u][v] = true;
            }
            ++depth;
        }
        return !need ? depth - 1 : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
