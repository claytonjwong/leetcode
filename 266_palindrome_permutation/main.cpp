/*
 * 266. Palindrome Permutation
 *
 * Q: https://leetcode.com/problems/palindrome-permutation/
 * A: https://leetcode.com/problems/palindrome-permutation/discuss/592736/Kt-Js-Py3-Cpp-Seen-Odd
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    bool canPermutePalindrome(string s, Set seen = {}) {
        for (auto c: s)
            if (!seen.insert(c).second)
                seen.erase(c);
        return seen.size() <= 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
