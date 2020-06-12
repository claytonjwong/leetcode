/*
 * 542. 01 Matrix
 *
 * Q: https://leetcode.com/problems/01-matrix/
 * A: https://leetcode.com/problems/01-matrix/discuss/682748/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Queue = queue<pair<int, int>>;
    using Map = unordered_map<int, unordered_map<int, bool>>;
    VVI updateMatrix(VVI& A, Queue q = {}, Map seen = {}) {
        auto M = A.size(),
             N = M ? A[0].size() : 0;
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                if (!A[i][j])
                    q.push({ i, j }), seen[i][j] = true;
        auto depth{ 1 };
        while (!q.empty()) {
            auto K = q.size();
            while (K--) {
                auto [i, j] = q.front(); q.pop();
                for (auto& dir: VVI{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) {
                    auto u = i + dir[0],
                         v = j + dir[1];
                    if (0 <= u && u < M && 0 <= v && v < N && !seen[u][v]) {
                        A[u][v] = depth;
                        q.push({ u, v }), seen[u][v] = true;
                    }
                }
            }
            ++depth;
        }
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
