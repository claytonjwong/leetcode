/*
 * 12. Integer to Roman
 *
 * Q: https://leetcode.com/problems/integer-to-roman/
 * A: https://leetcode.com/problems/integer-to-roman/discuss/469410/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num, string ans = {}) {
        while (num >= 1000) ans.push_back('M'), num -= 1000;
        while (num >=  900) ans.append("CM"),   num -= 900;
        while (num >=  500) ans.push_back('D'), num -= 500;
        while (num >=  400) ans.append("CD"),   num -= 400;
        while (num >=  100) ans.push_back('C'), num -= 100;
        while (num >=   90) ans.append("XC"),   num -= 90;
        while (num >=   50) ans.push_back('L'), num -= 50;
        while (num >=   40) ans.append("XL"),   num -= 40;
        while (num >=   10) ans.push_back('X'), num -= 10;
        while (num >=    9) ans.append("IX"),   num -= 9;
        while (num >=    5) ans.push_back('V'), num -= 5;
        while (num >=    4) ans.append("IV"),   num -= 4;
        while (num >=    1) ans.push_back('I'), num -= 1;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
