/*
 * 438. Find All Anagrams in a String
 *
 * Q: https://leetcode.com/problems/find-all-anagrams-in-a-string/
 * A: https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/618783/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<char, int>;
    VI findAnagrams(string s, string p, Map m = {}, VI ans = {}) {
        for (auto c: p)
            ++m[c];
        int N = s.size(),
                K = p.size(),
                need = K,
                i = 0,
                j = 0;
        while (j < N) {
            if (--m[s[j]] >= 0 && !--need) // no need unmet for anagram 🎯
                ans.push_back(i);
            if (++j - i == K) { // always expand, only shrink when the window size is reached
                if (++m[s[i]] >= 1)
                    ++need;
                ++i;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    auto ans = solution.findAnagrams("cbaebabacd", "abc");
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
