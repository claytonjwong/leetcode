/*
 * 977. Squares of a Sorted Array
 *
 * Q1: https://leetcode.com/problems/squares-of-a-sorted-array/
 * A1: https://leetcode.com/problems/squares-of-a-sorted-array/discuss/542713/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI sortedSquares(VI& A) {
        transform(A.begin(), A.end(), A.begin(), [](auto x) { return x * x; });
        sort(A.begin(), A.end());
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
