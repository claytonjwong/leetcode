/*
 * 540. Single Element in a Sorted Array
 *
 * Q: https://leetcode.com/problems/single-element-in-a-sorted-array/
 * A: https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/560588/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int singleNonDuplicate(VI& A) {
        int N = A.size(),
            i = 0,
            j = N;
        for (;;) {
            auto k = (i + j) / 2;
            auto min = k,
                 max = k;
            if (k > 0 && A[k - 1] == A[k])
                min = k - 1;
            if (k < N - 1 && A[k] == A[k + 1])
                max = k + 1;
            if (min == k && max == k) // target 🎯
                return A[k];
            if (min % 2) j = min; // 👈 left half has odd length
            if (max % 2) i = max; // 👉 right half has odd length
        }
        return 1e9 + 7;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
