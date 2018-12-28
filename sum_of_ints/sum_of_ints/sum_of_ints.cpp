/*
 
 371. Sum of Two Integers
 
 https://leetcode.com/problems/sum-of-two-integers/discuss/
 
 Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 
 Example:
 
 Given a = 1 and b = 2, return 3.
 
 
 
0001 a = 1
0010 b = 2

0011 = a ^ b = a
0000 = a & b
 
0011 = a ^ b = a   <== sum of a+b
0000 = a & b << 1

 
 
 
 
0001 = a = 1
0101 = b = 5
 
0100 = a ^ b = a
0001 = a & b

0100 = a ^ b = a
0010 = a & b << 1 = b

0110 = a ^ b = a
0000 = a & b
 
0110 = a ^ b = a
0000 = a & b << 1 = b
 
 
 
 a = -1 = 1111
 b =  1 = 0001
 
1110 = a ^ b = a
0001 = a & b = b

1110 = a ^ b = a
0010 = a & b << 1 ( carry over of 01+01 = 10 ) = b

1100 = a ^ b = a
0010 = a & b = b

1100 = a ^ b = a
0100 = a & b << 1 ( carry over of 10 + 10 = 100 ) = B

1000 = a ^ b = a
0100 = a & b = b

1000 = a ^ b = a
1000 = a & b << 1 = b

0000 = a ^ b = a
1000 = a & b = b

0000 = a ^ b = a
1000 = a & b = b
 
0000 = a ^ b = a
0000 = a & b << 1
 
          
 
 
 
 */

#include <iostream>

using namespace std;

class Solution {
public:
    
    //
    // a + b
    //
    int getSum(int a, int b) {
        
        if (a==0) { return b; }
        if (b==0) { return a; }
        
        while (b != 0){
            int carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        
        return a;
    }
    
    //
    // a - b
    //
    int getDiff(int a, int b){
        
        return getSum(a, ~b+1); // a-b == a+(-b)
        
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    int a,b;
    while (true){
        
        cout << "input a and b:" << endl;
        cin >> a;
        cin >> b;
        cout << a << "+" << b << "=" << solution.getSum(a, b) << endl;
        cout << a << "-" << b << "=" << solution.getDiff(a, b) << endl << endl << endl;
    }
    
    
    
    return 0;
}



