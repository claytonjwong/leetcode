/*
 * 941. Valid Mountain Array
 *
 * Q: https://leetcode.com/problems/valid-mountain-array/
 * A: https://leetcode.com/problems/valid-mountain-array/discuss/739686/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool validMountainArray(VI& A) {
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i + 1 < N  && A[i] < A[i + 1]) ++i; // climb mountain from left-to-right 👉
        while (0 <= j - 1 && A[j] < A[j - 1]) --j; // climb mountain from right-to-left 👈
        return 0 < i && i == j && j < N - 1; // 🎯 did we meet at the peak?
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
