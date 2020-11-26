/*
 * 395. Longest Substring with At Least K Repeating Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
 * A: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/949961/Kt-Js-Py3-Cpp-Recursively-Reduce-Search-Space-i..j
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    using Need = unordered_set<char>;
    using VI = vector<int>;
    int longestSubstring(string s, int T, int i = 0, int j = 1e4, Map m = {}, Need need = {}, int best = 0) {
        j = min(j, int(s.size()));
        for (auto k{ i }; k < j; ++m[s[k++]]);
        for (auto [c, cnt]: m)
            if (cnt < T)
                need.insert(c);
        if (need.empty())                        // 🎯 valid substring [i..j)
            return j - i;
        VI next{ i - 1 };                        // ⭐️ -1 since invalid indexes are non-inclusive, but i is inclusive
        for (auto k{ i }; k < j; ++k)
            if (need.find(s[k]) != need.end())
                next.push_back(k);
        next.push_back(j);
        for (auto k{ 1 }; k < next.size(); ++k)  // 🚀 recursively search for valid substrings in between next indexes (previous + 1 because next indexes are non-inclusive)
            best = max(best, longestSubstring(s, T, next[k - 1] + 1, next[k]));
        return best;
    }
};

int main() {
    Solution solution;
    cout << solution.longestSubstring("bbaaacbd", 3) << endl;
    return 0;
}
