/*
 * 238. Product of Array Except Self
 *
 * Q: https://leetcode.com/problems/product-of-array-except-self/
 * A: https://leetcode.com/problems/product-of-array-except-self/discuss/507330/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI productExceptSelf(VI& A, VI ans = {}) {
        int N = A.size();
        VI L(N + 1, 1),
           R(N + 1, 1);
        for (auto i = 1; i <= N; ++i)
            L[i] = L[i - 1] * A[i - 1];
        for (auto i = N - 1; i >= 0; --i)
            R[i] = R[i + 1] * A[i];
        for (auto i = 0; i < N; ++i)
            ans.push_back(L[i] * R[i + 1]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
