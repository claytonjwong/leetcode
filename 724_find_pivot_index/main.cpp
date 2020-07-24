/*
 * 724. Find Pivot Index
 *
 * Q: https://leetcode.com/problems/find-pivot-index/
 * A: https://leetcode.com/problems/find-pivot-index/discuss/751936/Javascript-Python3-C%2B%2B-Prefix-Sums
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int pivotIndex(VI& A) {
        int N = A.size();
        VI L(N),
           R(N);
        int beg = 1,
            end = N - 2;
        for (auto i{ beg }; i <  N; ++i) L[i] = L[i - 1] + A[i - 1]; // non-inclusive prefix sums from Left-to-right 👉
        for (auto j{ end }; 0 <= j; --j) R[j] = R[j + 1] + A[j + 1]; // non-inclusive suffix sums from Right-to-left 👈
        for (auto k{ 0 }; k < N; ++k)
            if (L[k] == R[k])
                return k; // 🎯 target at k-th index
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
