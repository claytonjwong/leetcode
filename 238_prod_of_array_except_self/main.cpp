/*
 * 238. Product of Array Except Self
 *
 * Q: https://leetcode.com/problems/product-of-array-except-self/
 * A: https://leetcode.com/problems/product-of-array-except-self/discuss/580963/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI productExceptSelf(VI& A) {
        int N = A.size();
        VI L(N),
                R(N);
        int beg = 0,
                end = N - 1;
        L[beg] = A[beg]; for (auto i = beg + 1; i < N;  ++i) L[i] = L[i - 1] * A[i]; // (L)eft-to-right 👉
        R[end] = A[end]; for (auto i = end - 1; i >= 0; --i) R[i] = R[i + 1] * A[i]; // (R)ight-to-left 👈
        VI ans(N, 1);
        for (auto i{ 0 }; i < N; ++i) {
            if (i > beg) ans[i] *= L[i - 1];
            if (i < end) ans[i] *= R[i + 1];
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
