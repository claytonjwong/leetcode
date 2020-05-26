/*
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 *
 * Q: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 * A: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/discuss/652437/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k, int cnt = 0, int max = 0) {
        auto isVowel = [](auto c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; };
        for (auto i{ 0 }; i < s.size(); ++i) {
            if (isVowel(s[i]))
                ++cnt;
            if (k <= i && isVowel(s[i - k]))
                --cnt;
            max = std::max(max, cnt);
        }
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
