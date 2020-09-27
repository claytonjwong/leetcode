/*
 * 482. License Key Formatting
 *
 * Q: https://leetcode.com/problems/license-key-formatting/
 * A: https://leetcode.com/problems/license-key-formatting/discuss/594395/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K, string ans = {}) {
        S.erase(remove_if(S.begin(), S.end(), [](auto c) { return c == '-'; }), S.end());
        transform(S.begin(), S.end(), S.begin(), [](auto c) { return toupper(c); });
        reverse(S.begin(), S.end());
        for (auto i{ 0 }; i < S.size(); ++i) {
            if (i > 0 && i % K == 0)
                ans.push_back('-');
            ans.push_back(S[i]);
        }
        return { ans.rbegin(), ans.rend() };
    }
};

namespace Queue {
    class Solution {
    public:
        using Deque = deque<char>;
        using Words = deque<string>;
        string licenseKeyFormatting(string S, int K, Words words = {}, ostringstream out = ostringstream()) {
            S.erase(remove_if(S.begin(), S.end(), [](auto c) { return c == '-'; }), S.end());
            transform(S.begin(), S.end(), S.begin(), ::toupper);
            while (S.size()) {
                auto take = min(int(S.size()), K);
                Deque word;
                while (take--)
                    word.push_front(S.back()), S.pop_back();
                words.push_front({ word.begin(), word.end() });
            }
            copy(words.begin(), words.end(), ostream_iterator<string>(out, "-"));
            auto ans = out.str();
            if (ans.size())
                ans.pop_back(); // pop trailing '-'
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
