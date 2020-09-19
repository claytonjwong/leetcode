/*
 * 1588. Sum of All Odd Length Subarrays
 *
 * Q: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
 * A: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/discuss/854147/Javascript-Python3-C%2B%2B-Prefix-Sums
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int sumOddLengthSubarrays(VI& A, int sum = 0) {
        int N = A.size();
        VI S(N + 1);
        for (auto i{ 1 }; i <= N; ++i)
            S[i] = S[i - 1] + A[i - 1];              // 🧩 prefix sums S
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ 1 }; i + j <= N; j += 2)    // 👀 odd length j: 1, 3, 5, ...
                sum += S[i + j] - S[i];
        return sum;                                  // 🎯 sum of odd length subarrays
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
