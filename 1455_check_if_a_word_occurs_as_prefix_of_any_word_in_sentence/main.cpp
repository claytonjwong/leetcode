/*
 * 1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
 *
 * Q: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
 * A: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/discuss/652390/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string S, string T, string word = {}) {
        istringstream is{ S };
        for (auto i{ 0 }; is >> word; ++i)
            if (word.substr(0, T.size()) == T)
                return i + 1; // 🎯 +1 for 1-based indexing
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
