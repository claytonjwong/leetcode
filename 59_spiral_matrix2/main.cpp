/*
 * 59. Spiral Matrix II
 *
 * Q: https://leetcode.com/problems/spiral-matrix-ii/
 * A: https://leetcode.com/problems/spiral-matrix-ii/discuss/430457/Kt-Js-Py3-Cpp-Step-and-Turn-Right
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI generateMatrix(int N) {
        VVI A(N, VI(N));
        auto i = 0,
             j = 0,
             k = 0;
        VVI dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  // clockwise 👆, 👉, 👇, 👈
        auto turn = [&]() { k = (k + 1) % 4; };
        auto step = [&]() {
            auto u = i + dirs[k][0],
                 v = j + dirs[k][1];
            if (0 <= u && u < N && 0 <= v && v < N && !A[u][v]) {
                i = u;
                j = v;
                return true;
            }
            return false;
        };
        auto steps = 1;
        A[0][0] = steps++;
        while (steps <= N * N) {
            while (step())
                A[i][j] = steps++;
            turn();
        }
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
