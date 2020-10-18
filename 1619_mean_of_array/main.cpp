/*
 * 1619. Mean of Array After Removing Some Elements
 *
 * Q: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
 * A: https://leetcode.com/problems/mean-of-array-after-removing-some-elements/discuss/898684/Kt-Js-Py3-Cpp-Sort-Trim-Average
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    double trimMean(VI& A) {
        int N = A.size(),
            K = N / 20;
        sort(A.begin(), A.end());
        return accumulate(A.begin() + K, A.end() - K, 0) / double(N - 2 * K);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
