/*
 * 1332. Remove Palindromic Subsequences
 *
 * Q: https://leetcode.com/problems/remove-palindromic-subsequences/
 * A: https://leetcode.com/problems/remove-palindromic-subsequences/discuss/490744/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        return s.empty() ? 0 : s == string(s.rbegin(), s.rend()) ? 1 : 2;
    }
};

int main() {
    Solution solution;
    cout << solution.removePalindromeSub("aabb") << endl;
    cout << solution.removePalindromeSub("aba") << endl;
    cout << solution.removePalindromeSub("") << endl;
    return 0;
}
