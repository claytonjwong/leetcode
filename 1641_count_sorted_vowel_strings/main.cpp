/*
 * 1641. Count Sorted Vowel Strings
 *
 * Q: https://leetcode.com/problems/count-sorted-vowel-strings/
 * A: https://leetcode.com/problems/count-sorted-vowel-strings/discuss/919428/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int countVowelStrings(int N, char last = '0', int total = 0) {
        if (!N)
            return 1;
        for (auto c: "aeiou")
            if (last <= c)
                total += countVowelStrings(N - 1, c);
        return total;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
