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
    VI productExceptSelf(VI& A) {
        int N = A.size();
        VI L{ A },
                R{ A };
        auto beg = 0,
                end = N - 1;
        for (auto i{ beg + 1 }; i <  N; ++i) L[i] = L[i - 1] * A[i]; // ⭐️ prefix products from 👉 (L)eft-to-right
        for (auto j{ end - 1 }; 0 <= j; --j) R[j] = R[j + 1] * A[j]; // ⭐️ prefix products from 👈 (R)ight-to-left
        transform(A.begin(), A.end(), A.begin(), [i = -1, beg, end, &L, &R](auto _) mutable {
            ++i;
            auto prod{ 1 };
            if (beg < i) prod *= L[i - 1];
            if (i < end) prod *= R[i + 1];
            return prod;
        });
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
