/*
 * 3. Longest Substring Without Repeating Characters
 *
 * Q: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * A: https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/504179/Javascript-Python3-C%2B%2B-Previously-Seen-Duplicate
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    int lengthOfLongestSubstring(string S, Map m = {}, int pre = -1, int max = 0) {
        for (auto i{ 0 }; i < S.size(); ++i) {
            auto c = S[i];
            pre = std::max(pre, m.find(c) != m.end() ? m[c] : -1), m[c] = i;  // 👀 track index of previously seen duplicate
            max = std::max(max, i - pre);                                     // 🎯 maximum substring length without duplicate
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
