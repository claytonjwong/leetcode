/*
 * 1540. Can Convert String in K Moves
 *
 * Q: https://leetcode.com/problems/can-convert-string-in-k-moves/
 * A: https://leetcode.com/problems/can-convert-string-in-k-moves/discuss/780454/Javascript-Python3-C%2B%2B-add-%2B-del-needs
 */

#include <iostream>
#include <unordered_map>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using Map = unordered_map<int, int>;
        bool canConvertString(string s, string t, int K, Map need = {}, int needs = 0) {
            if (s.size() != t.size())
                return false;
            // ✅ add needs
            for (auto i{ 0 }; i < s.size(); ++i) {
                auto diff = (t[i] - s[i] + 26) % 26;
                if (diff)
                    ++need[diff], ++needs;
            }
            // 🚫 del needs
            for (auto i{ 1 }; i <= K && needs; ++i) {
                auto diff = i % 26;
                if (need[diff])
                    --need[diff], --needs;
            }
            return !needs; // 🎯 no needs
        }
    };
}

namespace Concise {
    class Solution {
    public:
        using Map = unordered_map<int, int>;
        bool canConvertString(string s, string t, int T, Map need = {}) {
            if (s.size() != t.size())
                return false;
            // ✅ add needs
            for (auto i{ 0 }; i < s.size(); ++i) {
                auto k = (t[i] - s[i] + 26) % 26;
                if (k)
                    ++need[k];
            }
            // check if T is 🚫 insufficient for the needs
            for (auto [k, cnt]: need)
                if (T < k + (cnt - 1) * 26)
                    return false;
            return true; // 🎯 T is sufficient for the needs
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
