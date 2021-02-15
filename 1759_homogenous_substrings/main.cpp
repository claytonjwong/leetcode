/*
 * 1759. Count Number of Homogenous Substrings
 *
 * Q: https://leetcode.com/problems/count-number-of-homogenous-substrings/
 * A: https://leetcode.com/problems/count-number-of-homogenous-substrings/discuss/1064522/Kt-Js-Py3-Cpp-Dynamic-Progamming
 */

#include <iostream>
#include <vector>

using namespace std;

namespace verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int countHomogenous(string s, int mod = 1e9 + 7, int ans = 0) {
            int N = s.size();
            VI dp(N, 1);
            for (auto i{ 0 }; i < N; ++i) {
                if (i && s[i - 1] == s[i])
                    dp[i] = (dp[i] + dp[i - 1]) % mod;
                ans = (ans + dp[i]) % mod;
            }
            return ans;
        }
    };
}
namespace concise {
    class Solution {
    public:
        int countHomogenous(string s, int mod = 1e9 + 7, int pre = 1, int cur = 1, int last = '\0', int ans = 0) {
            for (auto c: s) {
                cur = c == last ? (1 + pre) % mod : 1;
                ans = (ans + cur) % mod;
                pre = cur, last = c;
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
