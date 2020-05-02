/*
 * 289. Game of Life
 *
 * Q: https://leetcode.com/problems/game-of-life/
 * A: https://leetcode.com/problems/game-of-life/discuss/607337/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    void gameOfLife(VVI& B) {
        int M = B.size(),
            N = M ? B[0].size() : 0;
        VVI A(M, VI(N)); // case 1 and case 3: dead by default ❌
        for (auto i{ 0 }; i < M; ++i) {
            for (auto j{ 0 }; j < N; ++j) {
                auto adj{ 0 };
                for (auto& dir: VVI{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}}) {
                    auto u = i + dir[0],
                         v = j + dir[1];
                    if (u < 0 || u == M || v < 0 || v == N)
                        continue;
                    adj += B[u][v];
                }
                if ((B[i][j] && (adj == 2 || adj == 3)) || (!B[i][j] && adj == 3))
                    A[i][j] = 1; // case 2 and case 4: live on ✅
            }
        }
        B = A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
