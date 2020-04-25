/*
 * 566. Reshape the Matrix
 *
 * Q: https://leetcode.com/problems/reshape-the-matrix/
 * A: https://leetcode.com/problems/reshape-the-matrix/discuss/597018/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI matrixReshape(VVI& A, int M, int N, VI line = {}) {
        auto i = A.size(),
                j = i ? A[0].size() : 0;
        if (i * j != M * N)
            return A;
        VVI ans(M, VI(N));
        for (auto k{ 0 }; k < M * N; ++k)
            ans[k / N][k % N] = A[k / j][k % j];
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
