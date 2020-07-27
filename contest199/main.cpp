/*
 * Contest: https://leetcode.com/contest/weekly-contest-199
 * Screenshare: https://www.youtube.com/watch?v=ufTyfhb0wQY&feature=youtu.be
 *
 * Rank            Name             Score    Finish Time    Q1 (3)     Q2 (4)	     Q3 (5)     Q4 (8)
 * 6247 / 14309    claytonjwong     7        0:32:15        0:04:16    0:27:15 *1
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

/*
 * 1528. Shuffle String
 *
 * Q: https://leetcode.com/problems/shuffle-string/
 * A: https://leetcode.com/problems/shuffle-string/discuss/756041/Javascript-Python3-C%2B%2B-create-t-from-s
 */
namespace Question1{
    class Solution {
    public:
        using VI = vector<int>;
        string restoreString(string s, VI& A) {
            int N = A.size();
            string t(N, '\0');
            for (auto i{ 0 }; i < N; ++i)
                t[A[i]] = s[i];
            return t;
        }
    };
}

/*
 * 1529. Bulb Switcher IV
 *
 * Q: https://leetcode.com/problems/bulb-switcher-iv/
 * A: https://leetcode.com/problems/bulb-switcher-iv/discuss/755780/Javascript-Python3-C%2B%2B-count-bit-flips
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        int minFlips(string s, char cur = '0', int cnt = 0) {
            for (auto c: s)
                if (cur != c)
                    cur = c, ++cnt;
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
