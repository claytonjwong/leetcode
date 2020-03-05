/*
 * 1368. Minimum Cost to Make at Least One Valid Path in a Grid
 *
 * Q: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
 * A: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/discuss/529142/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//
// TLE
//

//class Solution {
//public:
//    using VI = vector<int>;
//    using VVI = vector<VI>;
//    using Seen = unordered_map<int, unordered_map<int, unordered_map<int, bool>>>;
//    int minCost(VVI& A) {
//        int M = A.size(),
//            N = A[0].size();
//        auto bfs = [&](Seen seen = {}, VVI dirs = {{}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}) { // {sentinel, 👉, 👈, 👇, 👆}
//            VVI best(M, VI(N, 1e9 + 7));
//            queue<tuple<int, int, int>> q;
//            q.push({0, 0, 0});
//            seen[0][0][0] = true;
//            auto count = 0;
//            while (!q.empty()) {
//                auto [i, j, k] = q.front(); q.pop();
//                if (best[i][j] < k)
//                    continue;
//                best[i][j] = k;
//                for (auto d = 1; d < dirs.size(); ++d) {
//                    auto u = i + dirs[d][0],
//                         v = j + dirs[d][1],
//                         w = k + (d == A[i][j] ? 0 : 1);
//                    if (u < 0 || u >= M || v < 0 || v >= N || seen[u][v][w])
//                        continue;
//                    q.push({u, v, w});
//                    seen[u][v][w] = true;
//                }
//            }
//            return best[M - 1][N - 1];
//        };
//        return bfs();
//    }
//};

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Seen = unordered_map<int, unordered_map<int, unordered_map<int, bool>>>;
    int minCost(VVI& A) {
        auto bfs = [&](Seen seen = {}, VVI dirs = {{}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}}) { // {sentinel, 👉, 👈, 👇, 👆}
            int M = A.size(),
                N = A[0].size();
            VVI best(M, VI(N, 1e9 + 7));
            deque<tuple<int, int, int>> q;
            q.push_back({0, 0, 0});
            seen[0][0][0] = true;
            while (!q.empty()) {
                auto [i, j, k] = q.front(); q.pop_front();
                if (best[i][j] < k)
                    continue;
                best[i][j] = k;
                for (auto d = 1; d < dirs.size(); ++d) {
                    auto cost = d == A[i][j] ? 0 : 1;
                    auto u = i + dirs[d][0],
                         v = j + dirs[d][1],
                         w = k + cost;
                    if (u < 0 || u >= M || v < 0 || v >= N || seen[u][v][w])
                        continue;
                    if (cost)
                        q.push_back({u, v, w});
                    else
                        q.push_front({u, v, w});
                    seen[u][v][w] = true;
                }
            }
            return best[M - 1][N - 1];
        };
        return bfs();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
