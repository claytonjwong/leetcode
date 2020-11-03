/*
 * 1446. Consecutive Characters
 *
 * Q: https://leetcode.com/problems/consecutive-characters/
 * A: https://leetcode.com/problems/consecutive-characters/discuss/639815/Kt-Js-Py3-Cpp-Best-Same
 */

#include <iostream>

using namespace std;

namespace LastC {
    class Solution {
    public:
        int maxPower(string s, char last = '0', int same = 1, int best = 1) {
            for (auto c: s)
                if (last == c)
                    best = max(best, ++same);
                else
                    last = c, same = 1;
            return best;
        }
    };
}

namespace Indexed {
    class Solution {
    public:
        int maxPower(string s, int same = 1, int best = 1) {
            for (auto i{ 1 }; i < s.size(); ++i)
                if (s[i - 1] == s[i])
                    best = max(best, ++same);
                else
                    same = 1;
            return best;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
