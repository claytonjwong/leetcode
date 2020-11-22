/*
 * 159. Longest Substring with At Most Two Distinct Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
 * A: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/discuss/854873/Kt-Js-Py3-Cpp-Sliding-Window-%2B-Map
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    int lengthOfLongestSubstringTwoDistinct(string s, Map m = {}, int best = 0) {
        int N = s.size(),
            i = 0,
            j = 0;
        while (j < N) {
            ++m[s[j++]];              // ✅ expand window with s[j]
            while (2 < m.size()) {    // ❌ shrink window with s[i] until there are at most 2 distinct chars
                if (!--m[s[i]])
                    m.erase(s[i]);
                ++i;
            }
            best = max(best, j - i);  // 🎯 longest substring with at most 2 distinct chars
        }
        return best;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstringTwoDistinct("abaccc") << endl;
    return 0;
}
