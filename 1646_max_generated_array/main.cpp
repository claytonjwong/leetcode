/*
 * 1646. Get Maximum in Generated Array
 *
 * Q: https://leetcode.com/problems/get-maximum-in-generated-array/
 * A: https://leetcode.com/problems/get-maximum-in-generated-array/discuss/927494/Kt-Js-Py3-Cpp-Max-of-Generated-Array
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int getMaximumGenerated(int N, int best = 0) {
        if (N < 2)
            return N;
        VI A(N + 1);
        A[0] = 0;
        A[1] = 1;
        for (auto i{ 1 }; 2 * i <= N ; ++i) {
            if (2 * i     <= N) A[2 * i    ] = A[i];
            if (2 * i + 1 <= N) A[2 * i + 1] = A[i] + A[i + 1];
        }
        return *max_element(A.begin(), A.end());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
