/*
 
 8. String to Integer (atoi)
 
 https://leetcode.com/problems/string-to-integer-atoi/description/
 
 Implement atoi to convert a string to an integer.
 
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    int myAtoi(string s){
        
        if (s.empty()){
            return 0;
        }
        
        long long result = 0;
        
        char sign = ' ';
        
        string num = "";
        for (int i = (int)s.find_first_not_of(' '); i < (int)s.size(); i++){
            
            char curr = s[i];
            
            if ( curr == '-' || curr == '+' ){
                
                if (sign == ' '){ // sign can only be set once
                    sign = curr;
                } else {
                    return 0;
                }
                
            } else if ( isdigit(curr) ){
                
                num += curr;
                
            } else {
                
                break;
            }

            
        }
    
        if (num.size() > 10){
            
            if (sign == '-'){
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
        
        try{
            result = stoll(num);
        }
        catch (exception e){
            result = 0;
        }
        
        if (sign == '-'){
            result *= -1;
        }
        
        if (result < INT_MIN){
            return INT_MIN;
        }
        
        if (result > INT_MAX){
            return INT_MAX;
        }
        
        return (int)result;
    }
};


int main(int argc, const char * argv[]) {

    
    Solution solution;
    string test = "9223372036854775809";
    
    cout << to_string(solution.myAtoi(test)) << endl;
    
    
    
    return 0;
}




