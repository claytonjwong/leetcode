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
        auto N = s.size(),
                K = p.size();
        auto need{ K };
        for (auto i{ 0 }, j{ 0 }; j < N; ++j) {
            if (j - i == K) { // shrink when the window size is reached
                if (m.find(s[i]) != m.end()) {
                    ++m[s[i]]; // put
                    if (m[s[i]] > 0)
                        ++need; // post-increment need based on what's really needed
                }
                ++i;
            }
            if (m.find(s[j]) != m.end()) {
                if (m[s[j]] > 0)
                    --need; // pre-decrement need based on what's actually available
                --m[s[j]]; // take
            }
            if (!need) ans.push_back(i); // no need unmet for anagram at s[i..j] 🎯
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
