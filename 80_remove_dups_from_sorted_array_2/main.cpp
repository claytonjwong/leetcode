/*
 * 80. Remove Duplicates from Sorted Array II
 *
 * Q: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 * A: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/493516/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int removeDuplicates(VI& A, int i = 0) {
        for (auto x: A)
            if (i < 2 || A[i - 2] < x)
                A[i++] = x;
        return i;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
