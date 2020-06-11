/*
 * 1139. Largest 1-Bordered Square
 *
 * Q: https://leetcode.com/problems/largest-1-bordered-square/
 * A: https://leetcode.com/problems/largest-1-bordered-square/discuss/681894/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int largest1BorderedSquare(VVI& A, int max = 0) {
        int M = A.size(),
            N = A[0].size();
        VVI row(M, VI(N)),
            col(M, VI(N));
        auto ok = [&](auto i, auto j, auto k) {
            return A[i][j]
                && row[i][j + k] - row[i][j] == k           // top i-th row
                && col[i + k][j] - col[i][j] == k           // left j-th col
                && row[i + k][j + k] - row[i + k][j] == k   // bottom (i + k)-th row
                && col[i + k][j + k] - col[i][j + k] == k;  // right (j + k)-th col
        };
        row[0][0] = A[0][0];
        col[0][0] = A[0][0];
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                row[i][j] = !A[i][j] ? 0 : 1 + (0 <= j - 1 ? row[i][j - 1] : 0),
                col[i][j] = !A[i][j] ? 0 : 1 + (0 <= i - 1 ? col[i - 1][j] : 0);
        for (auto i{ 0 }; i < M; ++i)
            for (auto j{ 0 }; j < N; ++j)
                for (auto k{ 0 }; i + k < M && j + k < N; ++k)
                    if (ok(i, j, k))
                        max = std::max(max, k + 1); // k + 1 for edge end-points inclusive
        return max * max; // max side length squared == max 2D square area 🎯
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
