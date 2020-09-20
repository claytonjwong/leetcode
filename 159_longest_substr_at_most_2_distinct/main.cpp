/*
 * 159. Longest Substring with At Most Two Distinct Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/
 * A: https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/discuss/854873/Javascript-Python3-C%2B%2B-Sliding-Window-%2B-Map
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    int lengthOfLongestSubstringTwoDistinct(string s, Map m = {}, int best = 0) {
        int N = s.size(),
            i = 0,                                              // 👉 sliding window [i..j) ie. from i inclusive to j non-inclusive
            j = 0;
        while (j < N) {                                         // 💥 exit upon end of input string s
            while (2 < m.size()) {                              // 👉 shink window and 💥 exit upon reaching ✅ valid window with 🗺 at-most 2 distinct values
                if (m.find(s[i]) != m.end() && m[s[i]] == i)    // 🚫 delete s[i] at 🗺 right-most index i 👀 🤔
                    m.erase(s[i]);
                ++i;                                            // 👉 shrink window [i..j)
            }
            while (j < N && m.size() <= 2) {                    // 👉 expand window and 💥 exit upon end of input string s xor 🗺 addition of 3rd distinct value at index j
                m[s[j]] = j;                                    // 📝 remember s[j] is marked for 😵 future deletion at 🗺 right-most index j 👀 🤔
                j += m.size() <= 2;                             // 👉 expand window [i..j) while ✅ valid window with 🗺 at-most 2 distinct values
            }
            best = std::max(best, j - i);                       // 🎯 maximum valid window length from [i..j)
        }
        return best;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstringTwoDistinct("eceab") << endl;
    return 0;
}
