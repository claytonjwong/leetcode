/*
 * 1688. Count of Matches in Tournament
 *
 * Q: https://leetcode.com/problems/count-of-matches-in-tournament/
 * A: https://leetcode.com/problems/count-of-matches-in-tournament/discuss/970250/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfMatches(int N) {
        return N == 1 ? 0 : N / 2 + numberOfMatches(N / 2 + (N & 1));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
