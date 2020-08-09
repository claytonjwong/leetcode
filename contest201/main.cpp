/*
 * https://leetcode.com/contest/weekly-contest-201/
 * https://www.youtube.com/watch?v=cMqzxy8npo0&feature=youtu.be
 *
 * Rank            Name            Score    Finish Time    Q1 (3)     Q2 (4)    Q3 (6)   Q4 (7)
 * 3742 / 10002    claytonjwong    7        1:02:06        0:06:59    1:02:06
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * 1544. Make The String Great
 *
 * Q: https://leetcode.com/problems/make-the-string-great/
 * A: https://leetcode.com/problems/make-the-string-great/discuss/780878/Javascript-Python3-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        string makeGood(string t, string s = {}) {
            for (auto c: t)
                for (s.push_back(c); 2 <= s.size() && abs(s[s.size() - 2] - s[s.size() - 1]) == 32; s.pop_back(), s.pop_back());
            return s;
        }
    };
}

/*
 * 1545. Find Kth Bit in Nth Binary String
 *
 * Q: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * A: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/discuss/780890/Javascript-Python3-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using fun = function<string(int)>;
        char findKthBit(int n, int k) {
            fun go = [&](int i) -> string {
                if (!i)
                    return "0";
                auto pre = go(i - 1),
                     rev = pre;
                transform(rev.begin(), rev.end(), rev.begin(), [](auto c) { return c == '0' ? '1' : '0'; });
                return pre.append("1").append({ rev.rbegin(), rev.rend() });
            };
            return go(n - 1)[k - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
