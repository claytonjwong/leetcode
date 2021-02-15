/*
 * 161. One Edit Distance
 *
 * Q: https://leetcode.com/problems/one-edit-distance/
 * A: https://leetcode.com/problems/one-edit-distance/discuss/152967/Kt-Js-Py3-Cpp-Linear-Scan
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int M = s.size(),
            N = t.size();
        auto i = 0,
             j = 0,
             k = 0;
        while (abs(i - j) <= 1 && !(M <= i && N <= j))
            if ((i < M && j < N) && s[i] == t[j])
                ++i,
                ++j;
            else
                ++k,
                i = N <= M ? i + 1 : i,
                j = M <= N ? j + 1 : j;
        return k == 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
