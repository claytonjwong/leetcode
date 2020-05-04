/*
 * 81. Search in Rotated Sorted Array II
 *
 * Q: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 * A: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/611810/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool search(VI& A, int T) {
        int N = A.size(),
                i = 0,
                j = N - 1;
        while (i <= j) {
            auto k = (i + j) / 2;
            if (A[k] == T) // target 🎯
                return true;
            if (A[i] < A[k]) { // k is in the left "half"
                if (A[i] <= T && T < A[k])
                    j = k - 1; // T is in [i..k)
                else
                    i = k + 1; // T is in (k..j]
            }
            else if (A[i] > A[k]) { // k is in the right "half"
                if (A[k] < T && T <= A[j])
                    i = k + 1; // T is in (k..j]
                else
                    j = k - 1; // T is in [i..k)
            }
            else
                ++i; // determination of k's "half" is ambiguous, reduce search space
        }
        return false; // target not found ❌
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
