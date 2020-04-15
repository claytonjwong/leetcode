/*
 * 680. Valid Palindrome II
 *
 * Q: https://leetcode.com/problems/valid-palindrome-ii/
 * A: https://leetcode.com/problems/valid-palindrome-ii/discuss/580019/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool validPalindrome(string S) {
        int N = S.size(), i = 0, j = N - 1;
        while (i < j && S[i] == S[j]) ++i, --j;
        auto ok = [](string s) { return s == string{s.rbegin(), s.rend()}; };
        return i >= j || ok(S.substr(i, j - i)) || ok(S.substr(i + 1, j - i)); // with all, without j, without i
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
