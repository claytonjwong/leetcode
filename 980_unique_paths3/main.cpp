/*
 * 980. Unique Paths III
 *
 * Q: https://leetcode.com/problems/unique-paths-iii/
 * A: https://leetcode.com/problems/unique-paths-iii/discuss/856143/Kt-Js-Py3-Cpp-DFS-%2B-BT
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Dirs = vector<tuple<int, int>>;
    using fun = function<int(int, int, int)>;
    int uniquePathsIII(VVI& A, VI s = {}, VI t = {}, int total = 0, int paths = 0) {
        int M = A.size(),
            N = A[0].size();
        for (auto i{ 0 }; i < M; ++i) {
            for (auto j{ 0 }; j < N; ++j) {
                if (A[i][j] == 0) ++total;
                if (A[i][j] == 1) s = {i, j};
                if (A[i][j] == 2) t = {i, j};
            }
        }
        fun go = [&](int i, int j, int steps) {
            if (t[0] == i && t[1] == j)
                return steps == total ? ++paths : 0;
            for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}})
                if (0 <= u && u < M && 0 <= v && v < N && (!A[u][v] || A[u][v] == 2))
                    A[u][v] = -1,
                    go(u, v, steps + 1),
                    A[u][v] = 0;
            return paths;
        };
        return go(s[0], s[1], -1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
