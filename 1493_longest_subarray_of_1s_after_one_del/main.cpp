/*
 * 1493. Longest Subarray of 1's After Deleting One Element
 *
 * Q: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * A: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708212/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int longestSubarray(VI& A, int max = 0) {
        int N = A.size();
        VI L(N),
           R(N);
        auto beg = 0,
             end = N - 1;
        for (auto i{ beg }; i <  N; ++i) L[i] = A[i] ? (beg < i ? L[i - 1] + A[i] : A[i]) : 0; // prefix sums from Left-to-right 👉
        for (auto i{ end }; 0 <= i; --i) R[i] = A[i] ? (i < end ? R[i + 1] + A[i] : A[i]) : 0; // prefix sums from Right-to-left 👈
        for (auto i{ 0 }; i + 2 < N; ++i)
            max = std::max(max, L[i] + R[i + 2]); // maximum with a single gap 🎯
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
