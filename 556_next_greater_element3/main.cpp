/*
 * 556. Next Greater Element III
 *
 * Q: https://leetcode.com/problems/next-greater-element-iii/
 * A: https://leetcode.com/problems/next-greater-element-iii/discuss/983450/Kt-Js-Py3-Cpp-Brute-Force-Permutations
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    using LL = long long;
    static constexpr auto INF = 1e9 - 1;
    int nextGreaterElement(int T, LL best = INF) {
        stringstream stream; stream << T;
        string s = stream.str();
        next_permutation(s.begin(), s.end());
        LL cand = stoll(s);
        if (T < cand && cand < best)
            best = cand;
        return best < INF ? best : -1;
    }
};

int main() {
    Solution solution;
    cout << solution.nextGreaterElement(2147483647) << endl;
    return 0;
}
