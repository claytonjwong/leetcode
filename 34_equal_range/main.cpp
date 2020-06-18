/*
 * 34. Find First and Last Position of Element in Sorted Array
 *
 * Q: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * A: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/692931/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI searchRange(VI& A, int T) {
        auto [i, j] = equal_range(A.begin(), A.end(), T);
        int beg = distance(A.begin(), i),
            end = distance(A.begin(), j) - 1;
        return (i != A.end() && *i == T) ? VI{beg, end} : VI{-1, -1};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
