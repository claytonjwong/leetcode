/*
 
 633. Sum of Square Numbers
 
 https://leetcode.com/problems/sum-of-square-numbers/description/
 
 Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
 
 Example 1:
 Input: 5
 Output: True
 Explanation: 1 * 1 + 2 * 2 = 5
 Example 2:
 Input: 3
 Output: False
 
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqrt_c=(int)sqrt(c);
        for (int i=0; i <= sqrt_c; i++){
            int b2=i*i;
            int a2=c-b2;
            int a=sqrt(a2);
            a=a*a;
            if (a==a2){ return true; }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    solution.judgeSquareSum(2);
    
    return 0;
}





