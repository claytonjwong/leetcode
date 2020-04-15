/*
 * 125. Valid Palindrome
 *
 * Q: https://leetcode.com/problems/valid-palindrome/
 * A: https://leetcode.com/problems/valid-palindrome/discuss/580012/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), [](auto c) {
            return !isalnum(c) ? ' ' : isalpha(c) ? char(tolower(c)) : c;
        });
        s.erase(remove_if(s.begin(), s.end(), [](auto c) { return c == ' '; }), s.end());
        return s == string{s.rbegin(), s.rend()};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
