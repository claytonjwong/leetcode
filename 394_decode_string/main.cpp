/*
 * 394. Decode String
 *
 * Q: https://leetcode.com/problems/decode-string/
 * A: https://leetcode.com/problems/decode-string/discuss/941684/Kt-Js-Py3-Cpp-Stack
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using Stack = vector<string>;
    string decodeString(string encoded, string freq = {}, string word = {}, Stack s = {}) {
        for (auto c: encoded) {
            if (c == '[') {
                s.push_back(word), s.push_back(freq);
                freq = {}; word = {};
            }
            if (c == ']') {
                auto last_freq = s.back(); s.pop_back();
                auto last_word = s.back(); s.pop_back();
                ostringstream next; fill_n(ostream_iterator<string>(next), stoi(last_freq), word);
                word = last_word + next.str();
            }
            if (isdigit(c)) freq.push_back(c);
            if (isalpha(c)) word.push_back(c);
        }
        return word;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
