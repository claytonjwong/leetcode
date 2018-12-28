/*
 
 9. Palindrome Number
 
 Determine whether an integer is a palindrome. Do this without extra space.

 
 Some hints:
 Could negative integers be palindromes? (ie, -1)
 
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 
 There is a more generic way of solving this problem.
 
 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x<0){
            return false;
        }
        if (x<10){
            return true;
        }
        
        // 2^31-1 = 2147483647
        // 10^9   = 1000000000
        //          L        R
        //          i   ->
        
        int i=9;
        while (i >=0 and (int)(x/pow(10,i)) == 0){
            i--;
        }
        
        //
        // iterate while there are more digit positions to compare
        //
        while (i > 0){
            
            //
            // check left-most digit against right-most digit
            //
            int left = (int)(x/pow(10,i)) % 10;
            int right = x % 10;
            
            if ( left != right ){
                return false;
            }
            
            //
            // remove right-most digit
            //
            x = (int)x/10;
            
            //
            // subtract 2 from i since we want to move over 1 decimal position
            // and we divided x by 10 which removed the right-most digit
            //
            i-=2;
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    cout << "0 == " << solution.isPalindrome(1000021) << endl;
    cout << "1 == " << solution.isPalindrome(121) << endl;
    cout << "1 == " << solution.isPalindrome(12321) << endl;
    cout << "1 == " << solution.isPalindrome(1234321) << endl;
    return 0;
}

