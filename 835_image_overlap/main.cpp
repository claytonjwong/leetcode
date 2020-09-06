/*
 * 835. Image Overlap
 *
 * Q: https://leetcode.com/problems/image-overlap/
 * A: https://leetcode.com/problems/image-overlap/discuss/133614/Javascript-Python3-C%2B%2B-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int largestOverlap(VVI& A, VVI& B) {
        // 🎯  1. create T by padding B with N - 1 zeros
        int N = A.size(),
            K = N + 2 * (N - 1);
        VVI T(K, VI(K));
        auto offset{ N - 1 };
        for (auto i{ offset }; i <= 2 * offset; ++i)
            for (auto j{ offset }; j <= 2 * offset; ++j)
                T[i][j] = B[i - offset][j - offset];
        // 🔍  2. find max overlap by comparing A with all offsets in T
        auto max{ 0 };
        for (auto offset_i{ 0 }; offset_i <= 2 * offset; ++offset_i) {
            for (auto offset_j{ 0 }; offset_j <= 2 * offset; ++offset_j) {
                auto overlap{ 0 };
                for (auto i{ 0 }; i < N; ++i)
                    for (auto j{ 0 }; j < N; ++j)
                        overlap += A[i][j] & T[i + offset_i][j + offset_j];
                max = std::max(max, overlap);
            }
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
