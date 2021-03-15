/*
 * 1763. Longest Nice Substring
 *
 * Q: https://leetcode.com/problems/longest-nice-substring/
 * A: https://leetcode.com/problems/longest-nice-substring/discuss/1074560/Kt-Js-Py3-Cpp-Recursive
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using Set = unordered_set<char>;
    using fun = function<void(string&&)>;
    string longestNiceSubstring(string s, string best = {}) {
        fun go = [&](auto&& s) {
            Set seen{ s.begin(), s.end() };
            auto isNice = [&](auto c) {
                return seen.find(tolower(c)) != seen.end() && seen.find(toupper(c)) != seen.end();
            };
            for (auto i{ 0 }; i < s.size(); ++i) {
                if (!isNice(s[i])) {
                    go(s.substr(0, i)), go(s.substr(i + 1));
                    return;
                }
            }
            if (best.size() < s.size())
                best = s;
        };
        go(move(s));
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
