/*
 * 3. Longest Substring Without Repeating Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * A: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/504179/Kt-Js-Py3-Cpp-Best-i-Last-Seen-Duplicate-Index
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<char, int>;
    int lengthOfLongestSubstring(string s, Map m = {}, int last = -1, int best = 0) {
        for (auto i{ 0 }; i < s.size(); ++i) {
            last = max(last, m.find(s[i]) != m.end() ? m[s[i]] : -1), m[s[i]] = i;
            best = max(best, i - last);
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
