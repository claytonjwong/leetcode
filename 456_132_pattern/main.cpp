/*
 * 456. 132 Pattern
 *
 * Q: https://leetcode.com/problems/132-pattern/
 * A: https://leetcode.com/problems/132-pattern/discuss/907505/Kt-Js-Py3-Cpp-Trivial-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool find132pattern(VI& A) {
        int N = A.size(),
            first = A[0];
        for (auto j{ 1 }; j < N; ++j) {
            first = min(first, A[j]);  // ⭐️ minimum A[i] seen so far
            for (auto k{ j + 1 }; k < N; ++k)
                if (first < A[k] && A[k] < A[j])
                    return true;
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
