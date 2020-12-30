/*
 * 91. Decode Ways
 *
 * Q: https://leetcode.com/problems/decode-ways/
 * A: https://leetcode.com/problems/decode-ways/discuss/117143/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using fun = function<int(int)>;
        int numDecodings(string s) {
            auto N = s.size();
            auto ok = [](auto x) { return 1 <= x && x <= 26; };
            fun go = [&](auto i) {
                if (i == N)
                    return 1;
                auto cnt = 0,
                     one = stoi(s.substr(i, 1)),
                     two = one && i + 1 < N ? stoi(s.substr(i, 2)) : 0;
                if (ok(one)) cnt += go(i + 1);
                if (ok(two)) cnt += go(i + 2);
                return cnt;
            };
            return go(0);
        }
    };
}
namespace TopDownMemo {
    class Solution {
    public:
        using Map = unordered_map<int, int>;
        using fun = function<int(int)>;
        int numDecodings(string s, Map m = {}) {
            auto N = s.size();
            auto ok = [](auto x) { return 1 <= x && x <= 26; };
            fun go = [&](auto i) {
                if (m.find(i) != m.end())
                    return m[i];
                if (i == N)
                    return 1;
                auto cnt = 0,
                     one = stoi(s.substr(i, 1)),
                     two = one && i + 1 < N ? stoi(s.substr(i, 2)) : 0;
                if (ok(one)) cnt += go(i + 1);
                if (ok(two)) cnt += go(i + 2);
                return m[i] = cnt;
            };
            return go(0);
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int)>;
        int numDecodings(string s) {
            int N = s.size();
            VI dp(N + 2);
            dp[N] = 1;
            auto ok = [](auto x) { return 1 <= x && x <= 26; };
            for (auto i{ N - 1 }; 0 <= i; --i) {
                auto one = stoi(s.substr(i, 1)),
                     two = one && i + 1 < N ? stoi(s.substr(i, 2)) : 0;
                if (ok(one)) dp[i] += dp[i + 1];
                if (ok(two)) dp[i] += dp[i + 2];
            }
            return dp[0];
        }
    };
}
namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int)>;
        int numDecodings(string s) {
            int N = s.size(),
                a = 0,
                b = 1,
                c = 0;
            auto ok = [](auto x) { return 1 <= x && x <= 26; };
            for (auto i{ N - 1 }; 0 <= i; --i) {
                auto one = stoi(s.substr(i, 1)),
                     two = one && i + 1 < N ? stoi(s.substr(i, 2)) : 0;
                a = 0;
                if (ok(one)) a += b;
                if (ok(two)) a += c;
                c = b, b = a;
            }
            return a;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
