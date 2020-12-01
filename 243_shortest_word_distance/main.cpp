/*
 * 243. Shortest Word Distance
 *
 * Q: https://leetcode.com/problems/shortest-word-distance/
 * A: https://leetcode.com/problems/shortest-word-distance/discuss/670999/Kt-Js-Py3-Cpp-Last-Seen-K-th-Index
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    int shortestDistance(VS& A, string s, string t, int i = -1, int j = -1, int best = 1e9 + 7) {
        for (auto k{ 0 }; k < A.size(); ++k) {
            if (A[k] == s) i = k;
            if (A[k] == t) j = k;
            if (-1 < i && -1 < j)
                best = min(best, abs(i - j));
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
