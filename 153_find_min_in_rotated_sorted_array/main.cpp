/*
 * 153. Find Minimum in Rotated Sorted Array
 *
 * Q: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * A: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/discuss/716821/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int findMin(VI& A) {
            int N = A.size(),
                i = 0,
                j = N - 1;
            while (i < j) {
                auto k = (i + j) / 2;
                if (A[i] <= A[k] && A[k] <= A[j]) break;     // case 1: i..j is sorted, thus A[i] is the minimum 🎯
                if (A[j] <= A[i] && A[i] <= A[k]) i = k + 1; // case 2: k is in the 👈 left-most maximal partition of A
                if (A[k] <= A[j] && A[j] <= A[i]) j = k;     // case 3: k is in the 👉 right-most minimal partition of A
            }
            return A[i];
        }
    };
}

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int findMin(VI& A) {
            int N = A.size(),
                    i = 0,
                    j = N - 1;
            while (i < j) {
                auto k = (i + j) / 2;
                if (A[i] <= A[j]) break;     // case 1: i..j is sorted, thus A[i] is the minimum 🎯
                if (A[j] <= A[k]) i = k + 1; // case 2: k is in the 👈 left-most maximal partition of A
                if (A[k] <= A[j]) j = k;     // case 3: k is in the 👉 right-most minimal partition of A
            }
            return A[i];
        }
    };
}

namespace MostConcise {
    class Solution {
    public:
        using VI = vector<int>;
        int findMin(VI& A) {
            int N = A.size(),
                i = 0,
                j = N - 1;
            while (i < j && A[j] < A[i]) {
                auto k = (i + j) / 2;
                if (A[j] <= A[k]) i = k + 1; // case 2: k is in the 👈 left-most maximal partition of A
                if (A[k] <= A[j]) j = k;     // case 3: k is in the 👉 right-most minimal partition of A
            }
            return A[i];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
