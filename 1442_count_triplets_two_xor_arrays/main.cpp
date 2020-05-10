/*
 * 1442. Count Triplets That Can Form Two Arrays of Equal XOR
 *
 * Q: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
 * A: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/discuss/623806/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int countTriplets(VI& A, int cnt = 0) {
        int N = A.size();
        VI XOR(N + 1);
        for (auto i{ 1 }; i <= N; ++i)
            XOR[i] = XOR[i - 1] ^ A[i - 1];
        for (auto i{ 0 }; i < N; ++i) {
            for (auto j{ i + 1 }; j < N; ++j) {
                auto cur{ 0 };
                for (auto k{ j }; k < N; ++k) {
                    cur ^= A[k];
                    if ((XOR[i] ^ XOR[j]) == cur) // target 🎯
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
