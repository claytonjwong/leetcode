/*
 * 5. Longest Palindromic Substring
 *
 * Q: https://leetcode.com/problems/longest-palindromic-substring/
 * A: https://leetcode.com/problems/longest-palindromic-substring/discuss/635659/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s, int max = 1, string ans = {}) {
        int N = s.size();
        if (!N) return {};
        ans = s[0];
        auto expand = [&](auto i, auto j) {
            for (; 0 <= i && j < N && s[i] == s[j]; --i, ++j)
                if (max < j - i + 1)
                    max = j - i + 1, ans = s.substr(i, max); // +1 for i..j inclusive 🎯
        };
        for (auto i{ 0 }; i + 1 < N; ++i)
            expand(i, i),     // case 1: odd length palindrome
            expand(i, i + 1); // case 2: even length palindrome
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
