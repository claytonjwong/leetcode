/*
 * 1356. Sort Integers by The Number of 1 Bits
 *
 * Q: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 * A: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/discuss/519440/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI sortByBits(VI& A, VVI B = {}) {
        transform(A.begin(), A.end(), back_inserter(B), [](auto x) { return VI{__builtin_popcount(x), x}; });
        sort(B.begin(), B.end(), [](auto& a, auto& b) { return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        transform(B.begin(), B.end(), A.begin(), [](auto& a) { return a[1]; });
        return A;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
