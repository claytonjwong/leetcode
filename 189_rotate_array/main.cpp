/*
 * 189. Rotate Array
 *
 * Q: https://leetcode.com/problems/rotate-array/
 * A: https://leetcode.com/problems/rotate-array/discuss/895736/Kt-Js-Py3-Cpp-K-Rotations
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    void rotate(VI& A, int K) {
        std::rotate(A.rbegin(), A.rbegin() + (K % A.size()), A.rend());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
