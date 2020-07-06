/*
 * https://leetcode.com/contest/weekly-contest-196
 *
 * Weekly Contest 196 (Virtual)
 * Jul 05, 2020 at 3:29 PM
 * Duration    Score    Finish Time    AC    Ranking
 * 1 h 30 m    3/19     0:03:40        1/4   4003/8795
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <map>
#include <set>
#include <queue>

using namespace std;

/*
 * 1502. Can Make Arithmetic Progression From Sequence
 *
 * Q: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
 * A: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/721803/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
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
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
