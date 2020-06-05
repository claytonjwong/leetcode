/*
 * 243. Shortest Word Distance
 *
 * Q: https://leetcode.com/problems/shortest-word-distance-iii/
 * A: https://leetcode.com/problems/shortest-word-distance/discuss/670999/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    int shortestDistance(VS& A, string s, string t, int min = int(1e9 + 7)) {
        for (auto i{ -1 }, j{ -1 }, k{ 0 }; k < A.size(); ++k) {
            if (A[k] == s) i = k;
            if (A[k] == t) j = k;
            if (-1 < i && -1 < j)
                min = std::min(min, abs(i - j));
        }
        return min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
