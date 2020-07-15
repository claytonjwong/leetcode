/*
 * 151. Reverse Words in a String
 *
 * Q: https://leetcode.com/problems/reverse-words-in-a-string/
 * A: https://leetcode.com/problems/reverse-words-in-a-string/discuss/737631/Javascript-Python3-C%2B%2B
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    string reverseWords(string s, string word = {}, VS words = {}) {
        istringstream is{ s };
        while (is >> word)
            words.push_back(word);
        ostringstream os; copy(words.rbegin(), words.rend(), ostream_iterator<string>(os, " "));
        auto ans = os.str();
        if (ans.size())
            ans.pop_back(); // 🚫 remove trailing whitespace
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
