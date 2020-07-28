/*
 * 557. Reverse Words in a String III
 *
 * Q: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 * A: https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/759448/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    string reverseWords(string s, VS A = {}) {
        ostringstream os;
        istringstream is{ s };
        transform(istream_iterator<string>(is), istream_iterator<string>(), back_inserter(A), [](auto& s) {
            return string{ s.rbegin(), s.rend() };
        });
        copy(A.begin(), A.end(), ostream_iterator<string>(os, " "));
        auto t = os.str();
        if (t.size())
            t.pop_back(); // pop trailing whitespace
        return t;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
