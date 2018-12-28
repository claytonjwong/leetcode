/*
 
 660. Remove 9
 
 https://leetcode.com/contest/leetcode-weekly-contest-45/problems/remove-9/
 
 Start from integer 1, remove any integer that contains 9 such as 9, 19, 29...
 
 So now, you will have a new integer sequence: 1, 2, 3, 4, 5, 6, 7, 8, 10, 11, ...
 
 Given a positive integer n, you need to return the n-th integer after removing. Note that 1 will be the first integer.
 
 Example 1:
 Input: 9
 Output: 10
 Hint: n will not exceed 9 x 10^8.
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int newInteger(int n){
        
        //
        // return n base 9
        //
        string base9 = "";
        
        while ( n > 0){
            
            //
            // right-most base9 digit, add onto the front of the string
            //
            base9 = to_string(n % 9) + base9;
            
            //
            // right-shift n base9, this removes the right-most digit base9
            //
            n /= 9;
        }
        
        return stoi(base9);
    }
};


int main(int argc, const char * argv[]) {

    Solution solution;
    
    int n;
    
    while (true){
    
        cout << "Enter n: ";
        cin >> n;
        cout << endl << n << " base 9 = " << solution.newInteger(n) << endl;
    }
    
    
    
    return 0;
}





