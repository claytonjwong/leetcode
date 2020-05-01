/*
 * 278. First Bad Version
 *
 * Q: https://leetcode.com/problems/first-bad-version/
 * A: https://leetcode.com/problems/first-bad-version/discuss/606733/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

bool isBadVersion(int x); // forward declaration

class Solution {
public:
    int firstBadVersion(int N) {
        auto i = 0,
             j = N;
        while (i < j) {
            auto k = i + (j - i) / 2; // auto k = (i + j) / 2;
            if (!isBadVersion(k))
                i = k + 1;
            else
                j = k;
        }
        return i;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
