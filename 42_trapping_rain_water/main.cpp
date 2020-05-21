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
    int trap(VI& A, int sum = 0) {
        int N = A.size();
        VI L(N),
                R(N);
        auto beg{ 0 },
                end{ N - 1 };
        for (auto i{ beg }; i < N;  ++i) L[i] = max(A[i], i > beg ? L[i - 1] : 0); // (L)eft-to-right 👉
        for (auto j{ end }; 0 <= j; --j) R[j] = max(A[j], j < end ? R[j + 1] : 0); // (R)ight-to-left 👈
        for (auto i{ 1 }; i + 1 < N; ++i)
            sum += min(L[i], R[i]) - A[i]; // accumulate water sum per column i 🎯
        return sum;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
