/*
 * 1572. Matrix Diagonal Sum
 *
 * Q: https://leetcode.com/problems/matrix-diagonal-sum/
 * A: https://leetcode.com/problems/matrix-diagonal-sum/discuss/830407/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

namespace OneLiner {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int diagonalSum(VVI& A, int sum = 0) {
            int N = A.size();
            return accumulate(A.begin(), A.end(), 0, [i = -1, N, &A](auto sum, auto _) mutable {
                ++i; return sum + A[i][i] + A[i][N - 1 - i];
            }) - (N & 1 ? A[N / 2][N / 2] : 0);
        }
    };
}
namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int diagonalSum(VVI& A, int sum = 0) {
            int N = A.size();
            for (auto i{ 0 }; i < N; ++i)
                sum += A[i][i] + A[i][N - 1 - i];  // 🎯 accumulate sum of both diagonals simultaneously
            if (N & 1)
                sum -= A[N / 2][N / 2];            // ⭐️ subtract middle element once if it was added twice
            return sum;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
