/*
 
 246. Strobogrammatic Number
 
 https://leetcode.com/problems/strobogrammatic-number/description/
 
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Write a function to determine if a number is strobogrammatic. The number is represented as a string.
 
 For example, the numbers "69", "88", and "818" are all strobogrammatic.
 
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    bool isStrobogrammatic(string num) {
        
        if (num.empty()) { return true; }
        
        if (isMatchingPair(num[0], num[num.size()-1])){
            if ( num.size() < 3 ){
                return true;
            } else {
                return isStrobogrammatic( num.substr(1, num.size()-2) );
            }
        }
        
        return false;
        
    }
    
    bool isMatchingPair(char& first, char& last){
        
        if ( (first == last) && (first=='0' || first=='1' || first=='8') ){
            return true;
        }
        
        if ( (first == '6' && last == '9') || (first =='9' && last == '6') ) {
            return true;
        }
        
        return false;
    }
};


int main(int argc, const char * argv[]) {

    
    string num;
    Solution solution;
    
    while (true){
        
        cout << "Enter num:";
        cin >> num;
        cout << "isStrobogrammatic: " << solution.isStrobogrammatic(num) << endl << endl;
    }
    
    return 0;
}





