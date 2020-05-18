/*
 * 567. Permutation in String
 *
 * Q: https://leetcode.com/problems/permutation-in-string/
 * A: https://leetcode.com/problems/permutation-in-string/discuss/551220/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        bool checkInclusion(string pattern, string s, Map m = {}) {
            for (auto c: pattern)
                ++m[c];
            int N = s.size(),
                    K = pattern.size(),
                    i = 0,
                    j = 0,
                    need = K;
            while (j < N) {
                if (m[s[j]]-- > 0 && !--need) // no need unmet for anagram at s[i..j] 🎯
                    return true;
                if (++j - i == K) { // always expand, only shrink when the window size is reached
                    if (++m[s[i]] > 0) ++need;
                    ++i;
                }
            }
            return false;
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        bool checkInclusion(string pattern, string A, Map m = {}) {
            for (auto c: pattern)
                ++m[c];
            auto K = pattern.size(),
                 need = K;
            for (auto i{ 0 }, j{ 0 }; j < A.size(); ++j) {
                if (j - i == K) { // shrink window
                    if (++m[A[i]] > 0) // put
                        ++need; // post-increment need based on what's really needed
                    ++i;
                }
                if (m[A[j]]-- > 0) // take
                    --need; // pre-decrement need based on what's actually available
                if (!need) // no need unmet for anagram at s[i..j] 🎯
                    return true;
            }
            return false;
        }
    };
}

int main() {
    Concise::Solution solution;
    cout << solution.checkInclusion("ab", "ab") << endl;
    return 0;
}
