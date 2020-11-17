/*
 * 845. Longest Mountain in Array
 *
 * Q: https://leetcode.com/problems/longest-mountain-in-array/
 * A: https://leetcode.com/problems/longest-mountain-in-array/discuss/135623/Kt-Js-Py3-Cpp-Mountain-Peak
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int longestMountain(VI& A, int best = 0) {
        int N = A.size();
        for (auto k{ 1 }; k + 1 < N; ++k) {
            auto i = k,
                 j = k;
            while (0 <= i - 1 && A[i - 1] < A[i]) --i;
            while (j + 1 < N  && A[j] > A[j + 1]) ++j;
            if (i < k && k < j)
                best = max(best, j - i + 1);  // +1 for i..j inclusive
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
