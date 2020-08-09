/*
 * 1544. Make The String Great
 *
 * Q: https://leetcode.com/problems/make-the-string-great/
 * A: https://leetcode.com/problems/make-the-string-great/discuss/780878/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string makeGood(string t, string s = {}) {
        for (auto c: t)
            for (s.push_back(c); 2 <= s.size() && abs(s[s.size() - 2] - s[s.size() - 1]) == 32; s.pop_back(), s.pop_back());
        return s;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
