/*
 * 340. Longest Substring with At Most K Distinct Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
 * A: https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/discuss/992358/Kt-Js-Py3-Cpp-Sliding-Window-%2B-Map
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    int lengthOfLongestSubstringKDistinct(string s, int k, Map m = {}, int best = 0) {
        int i = 0,
            j = 0,
            N = s.size();
        while (j < N) {
            ++m[s[j++]];
            while (k < m.size()) {    // ⭐️ maintain invariant
                if (!--m[s[i]])
                    m.erase(s[i]);
                ++i;
            }
            best = max(best, j - i);  // 🎯 maximum length window
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
