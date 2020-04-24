/*
 * 171. Excel Sheet Column Number
 *
 * Q: https://leetcode.com/problems/excel-sheet-column-number/
 * A: https://leetcode.com/problems/excel-sheet-column-number/discuss/594372/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    using LL = long long;
    int titleToNumber(string S, int ans = 0) {
        int N = S.size();
        for (LL i{ N - 1 }, j{ 1 }; i >= 0; --i, j *= 26)
            ans += (S[i] - 'A' + 1) * j;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
