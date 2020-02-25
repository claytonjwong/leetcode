/*
 * 1358. Number of Substrings Containing All Three Characters
 *
 * Q: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
 * A: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/520463/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using Map = unordered_map<int, int>;
    int numberOfSubstrings(string s, Map cnt = {}, int ans = 0) {
        for (auto i = 0, j = 0; j < s.size(); ++j) {
            ++cnt[s[j]];
            while (cnt['a'] && cnt['b'] && cnt['c'])
                --cnt[s[i++]];
            ans += i;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
