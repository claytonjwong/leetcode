/*
 
 29. Divide Two Integers
 
 https://leetcode.com/problems/divide-two-integers/#/description
 
 Divide two integers without using multiplication, division and mod operator.
 
 If it is overflow, return MAX_INT.
 
 */

#include <iostream>
#include <climits>

using namespace std;


class Solution {
public:
    int divide(int dividend, int divisor) {
        
        // sanity checks
        if (divisor==0){
            return INT_MAX;
        }
        
        if (dividend==0){
            return 0;
        }
        
        if (dividend == divisor){
            return 1;
        }
        
        // keep all calculations using positive numbers, then multiply by -1 at the end if negative
        bool is_negative = false;
        
        if (( dividend<0 && divisor >0 ) || ( dividend>0 && divisor<0 )){
            is_negative = true;
        }
        
        long long_dividend = abs((long)dividend);
        long long_divisor = abs((long)divisor);
        
        if (long_divisor==1){
            
            if ( (long_dividend>INT_MAX && ! (is_negative))  ||  (long_dividend<-INT_MAX && ! (is_negative)) ){
                return INT_MAX;
            }
            if(long_dividend>INT_MAX && is_negative){
                return INT_MAX+1;
            }
            
            if (is_negative){
                return (int)long_dividend * -1;
            } else {
                return (int)long_dividend;
            }
        }
        
        // 26 / 5
        
        // find the largest power of 2 mutliplied by long_divisor via lshift
        // and subtract this largest power of 2 "chunk" from the long_divisor
        // then sum up the lshifts and lshift 1 by that many shifts,
        // this is how many times long_dividend has been divided by long_divisor so far
        int sum_of_shifts=0;
        int cnt=0;
        while (long_dividend >= long_divisor){
            
            cnt=0;
            long largest_chunk = long_divisor;
            while (true){
                if (long_dividend >= (largest_chunk<<1) && (largest_chunk<<1 > largest_chunk)){
                    largest_chunk <<= 1;
                    cnt++;
                } else {
                    break;
                }
            }
            long_dividend -= largest_chunk;
            sum_of_shifts += (1<<cnt);
            
        }
        
        if (is_negative){
            sum_of_shifts *= -1;
        }
        return sum_of_shifts;
        
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << "5 == " << solution.divide(-2147483648, 2) << endl << endl;
    cout << -(INT_MAX+1) << endl << endl;
    
    return 0;
}
