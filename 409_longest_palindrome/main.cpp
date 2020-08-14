/*
 * 409. Longest Palindrome
 *
 * Q: https://leetcode.com/problems/longest-palindrome/
 * A: https://leetcode.com/problems/longest-palindrome/discuss/791485/Javascript-Python3-C%2B%2B-even-count-odd-count-%2B-1
 */

#include <iostream>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    int longestPalindrome(string s, Map m = {}) {
        for (auto c: s) ++m[c];
        auto odd = accumulate(m.begin(), m.end(), 0, [](auto& cnt, auto& pair) { return cnt + pair.second % 2; });
        return s.size() - odd + (odd ? 1 : 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
