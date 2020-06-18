/*
 * 28. Implement strStr()
 *
 * Q: https://leetcode.com/problems/implement-strstr/
 * A: https://leetcode.com/problems/implement-strstr/discuss/694155/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        auto i = haystack.find(needle);
        return i != string::npos ? i : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
