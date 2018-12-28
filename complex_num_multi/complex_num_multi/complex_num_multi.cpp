/*
 
 537. Complex Number Multiplication
 
 https://leetcode.com/problems/complex-number-multiplication/description/
 
 Given two strings representing two complex numbers.
 
 You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
 
 Example 1:
 Input: "1+1i", "1+1i"
 Output: "0+2i"
 Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
 Example 2:
 Input: "1+-1i", "1+-1i"
 Output: "0+-2i"
 Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
 Note:
 
 The input strings will not have extra blank.
 The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
 
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        char c;
        int ra,ia,rb,ib;
        stringstream in,out;
        in << a; in >> ra >> c >> ia >> c;
        in << b; in >> rb >> c >> ib >> c;
        out << (ra*rb)-(ia*ib) << "+" << (ra*ib)+(rb*ia) << "i";
        return out.str();
    }
};

int main(int argc, const char * argv[]) {

    Solution s;
    string a="1+-1i",b="1+-1i";
    cout << s.complexNumberMultiply(a, b) << endl;
    
    
    return 0;
}



