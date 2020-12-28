/*
 * 1704. Determine if String Halves Are Alike
 *
 * Q: https://leetcode.com/problems/determine-if-string-halves-are-alike/
 * A: https://leetcode.com/problems/determine-if-string-halves-are-alike/discuss/988139/kt-js-py3-cpp-halves-equal-vowel-count
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    bool halvesAreAlike(string s, Set vowel = Set{ 'a', 'e', 'i', 'o', 'u' }) {
        auto N = s.size();
        auto K = N / 2;
        auto a = s.substr(0, K),
             b = s.substr(K);
        auto isVowel = [&](auto c) { return vowel.find(tolower(c)) != vowel.end(); };
        return count_if(a.begin(), a.end(), isVowel) == count_if(b.begin(), b.end(), isVowel);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
