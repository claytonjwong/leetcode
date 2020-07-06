/*
 * 1502. Can Make Arithmetic Progression From Sequence
 *
 * Q: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * A: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/721803/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool canMakeArithmeticProgression(VI& A) {
        sort(A.begin(), A.end());
        for (auto i{ 1 }; i < A.size(); ++i)
            if (A[i - 1] - A[i] != A[0] - A[1])
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
