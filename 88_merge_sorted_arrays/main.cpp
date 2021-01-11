/*
 * 88. Merge Sorted Array
 *
 * Q: https://leetcode.com/problems/merge-sorted-array/
 * A: https://leetcode.com/problems/merge-sorted-array/discuss/670661/Kt-Js-Py3-Cpp-Merge-from-Right-to-Left
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    void merge(VI& A, int M, VI& B, int N) {
        auto i = M - 1,
             j = N - 1,
             k = M + N - 1;
        while (0 <= j)
            A[k--] = i < 0 || A[i] < B[j] ? B[j--] : A[i--];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
