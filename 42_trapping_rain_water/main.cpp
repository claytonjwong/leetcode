/*
 * 42. Trapping Rain Water
 *
 * Q: https://leetcode.com/problems/trapping-rain-water/
 * A: https://leetcode.com/problems/trapping-rain-water/discuss/512006/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     using VI = vector<int>;
//     int trap(VI& A, int ans = 0) {
//         int N = A.size();
//         for (auto i = 1; i + 1 < N; ++i) {
//             auto L = 0; for (auto j = i - 1; j > -1; --j) L = max(L, A[j]);
//             auto R = 0; for (auto j = i + 1; j <  N; ++j) R = max(R, A[j]);
//             ans += max(min(L, R) - A[i], 0);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    using VI = vector<int>;
    int trap(VI& A, int ans = 0) {
        int N = A.size();
        if (N < 3)
            return 0;
        auto beg = 0, end = N - 1;
        VI L(N, A[beg]); for (auto i = beg + 1; i <  N; ++i) L[i] = max(L[i - 1], A[i]);
        VI R(N, A[end]); for (auto i = end - 1; i > -1; --i) R[i] = max(R[i + 1], A[i]);
        for (auto i = 1; i + 1 < N; ++i)
            ans += max(min(L[i], R[i]) - A[i], 0);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
