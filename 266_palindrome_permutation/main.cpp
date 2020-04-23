/*
 * 266. Palindrome Permutation
 *
 * Q: https://leetcode.com/problems/palindrome-permutation/
 * A: https://leetcode.com/problems/palindrome-permutation/discuss/592736/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

namespace Map {
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
namespace Set {
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
