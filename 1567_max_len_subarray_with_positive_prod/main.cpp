/*
 * 1567. Maximum Length of Subarray With Positive Product
 *
 * Q: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
 * A: https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/discuss/822464/Javascript-Python3-C%2B%2B-Sliding-Window
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int getMaxLen(VI& A, int even = 1, int max = 0) {
        A.push_back(0);  // ⭐️ sentinel value
        int N = A.size(),
            i = 0,
            j = 0;
        while (i != N) {
            // case 1: ➖ collapse window [i 👉 ..j]
            while (j < N && !A[j]) {
                while (i < j) {
                    if (A[i++] < 0) even ^= 1;
                    if (even) max = std::max(max, j - i);
                }
                i = ++j;
            }
            // case 2: ➕ expand window [i..j 👉 ]
            while (j < N && A[j]) {
                if (A[j++] < 0) even ^= 1;
                if (even) max = std::max(max, j - i);
            }
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
