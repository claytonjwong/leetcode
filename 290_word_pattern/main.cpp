/*
 * 290. Word Pattern
 *
 * Q: https://leetcode.com/problems/word-pattern/
 * A: https://leetcode.com/problems/word-pattern/discuss/622795/Javascript-Python3-C%2B%2B-.-Map-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Pattern = unordered_map<char, string>;
    using Text = unordered_map<string, char>;
    using Words = vector<string>;
    bool wordPattern(string chars, string B, string word = {}, Words words = {}, Pattern P = {}, Text T = {}) {
        for (istringstream is{ B }; is >> word; words.emplace_back(word));
        if (chars.size() != words.size())
            return false;
        int N = chars.size();
        for (auto i{ 0 }; i < N; ++i) {
            auto [ c, w ] = tie(chars[i], words[i]);
            if (P.find(c) != P.end() && P[c] != w) return false;  // 🚫 char c not mapped to word w
            if (T.find(w) != T.end() && T[w] != c) return false;  // 🚫 word w not mapped to char c
            if (P.find(c) == P.end()) P[c] = w;                   // map char c 👉 word w
            if (T.find(w) == T.end()) T[w] = c;                   // map word w 👉 char c
        }
        return true;  // ✅ OK
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
