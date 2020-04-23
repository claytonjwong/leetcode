/*
Apple Phone Interview
Completed April 22, 2020 6:11 PM
Time Spent: 10 minutes 35 seconds
Time Allotted: 1 hour 30 minutes
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
 * 594. Longest Harmonious Subsequence
 *
 * Q: https://leetcode.com/problems/longest-harmonious-subsequence/
 * A: https://leetcode.com/problems/longest-harmonious-subsequence/discuss/592722/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        int findLHS(VI& A, Map m = {}, int max = 0) {
            for (auto x: A)
                ++m[x];
            for (auto& [x, _]: m)
                if (m.find(x - 1) != m.end())
                    max = std::max(max, m[x - 1] + m[x]);
            return max;
        }
    };
}

/*
 * 266. Palindrome Permutation
 *
 * Q: https://leetcode.com/problems/palindrome-permutation/
 * A: https://leetcode.com/problems/palindrome-permutation/discuss/592736/Javascript-and-C%2B%2B-solutions
 */
namespace Question2_Map {
    class Solution {
    public:
        using Map = unordered_map<char, int>;
        bool canPermutePalindrome(string s, Map m = {}, int odd = 0) {
            for (auto c: s)
                ++m[c];
            for (auto& [_, cnt]: m)
                odd += cnt % 2;
            return odd < 2;
        }
    };
}
namespace Question2_Set {
    class Solution {
    public:
        bool canPermutePalindrome(string s, set<int> seen = {}) {
            for (auto c: s)
                if (!seen.insert(c).second)
                    seen.erase(c);
            return seen.size() < 2;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
