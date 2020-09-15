/*
 * 58. Length of Last Word
 *
 * Q: https://leetcode.com/problems/length-of-last-word/
 * A: https://leetcode.com/problems/length-of-last-word/discuss/847943/Javascript-Python3-C%2B%2B-Simple-solutions
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s, string last = {}) {
        istringstream stream{ s };
        while (stream >> last);
        return last.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
