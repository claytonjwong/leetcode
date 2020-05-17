/*
 * 5. Longest Palindromic Substring
 *
 * Q: https://leetcode.com/problems/longest-palindromic-substring/
 * A: https://leetcode.com/problems/longest-palindromic-substring/discuss/635659/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        string longestPalindrome(string s) {
            int N = s.size();
            if (!N) return {};
            string ans{ s[0] };
            go(ans, s, 0, N - 1);
            return ans;
        }
    private:
        bool go(string& ans, string& s, int i, int j) {
            auto best = [&](auto i, auto j) {
                if (ans.size() < j - i + 1)        // +1 for i..j inclusive
                    ans = s.substr(i, j - i + 1);  // +1 for i..j inclusive 🎯
            };
            if (j - i < 2) {
                if (s[i] == s[j]) {
                    best(i, j);
                    return true;
                }
                return false;
            }
            go(ans, s, i + 1, j);           // case 1: the sub-problem without the character at index i
            go(ans, s, i, j - 1);           // case 2: the sub-problem without the character at index j
            if (go(ans, s, i + 1, j - 1)) { // case 3: the sub-problem without the character at index i and j
                if (s[i] == s[j]) {
                    best(i, j);
                    return true;
                }
            }
            return false;
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        string longestPalindrome(string s) {
            int N = s.size();
            if (!N) return {};
            VVI dp(N, VI(N));
            string ans{ s[0] };
            for (auto j{ 1 }; j < N; ++j) {
                for (auto i{ j }; i >= 0; --i) {
                    dp[i][j] = s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]);
                    if (dp[i][j] && ans.size() < j - i + 1)
                        ans = s.substr(i, j - i + 1); // +1 for i..j inclusive 🎯
                }
            }
            return ans;
        }
    };
}

namespace BruteForce {
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
}

int main() {
    TopDown::Solution solution;
    cout << solution.longestPalindrome("abb") << endl;
    return 0;
}
