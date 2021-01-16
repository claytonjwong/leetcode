/*
 * 215. Kth Largest Element in an Array
 *
 * Q: https://leetcode.com/problems/kth-largest-element-in-an-array/
 * A: https://leetcode.com/problems/kth-largest-element-in-an-array/discuss/153981/Kt-Js-Py3-Cpp-Sort
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findKthLargest(VI& A, int K) {
        int N = A.size();
        sort(A.begin(), A.end());
        return A[N - K];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
