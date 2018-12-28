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
        for (int i=0; i <= sqrt(c); i++){
            int a2=i*i;
            int b2=c-a2;
            int b=sqrt(b2);
            if (a2+(b*b)==c) { return true; }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;
    while (true){
        int c;
        cout << "c: ";
        cin >> c;
        cout << solution.judgeSquareSum(c) << endl << endl;
    }
    
    
    
    return 0;
}




