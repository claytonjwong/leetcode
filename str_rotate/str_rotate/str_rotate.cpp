/*
 
 Assume you have a method is_substring which checks if one word is a substring of another.  Given two strings s1 and s2, write code to check if s2 is a rotation of s2 using only one call to isSubstring (e.g. "waterbottle" is a rotation of "erbottlewat"
 
 */

#include <iostream>
#include <string>

using namespace std;



class Solution{
public:
    
    bool is_substring(string s1, string s2){
        return s1.find(s2) != std::string::npos;
    }
    
    bool is_rotation(string s1, string s2){
        
        // sanity checks
        if ( s1.empty() or s2.empty() ){
            return false;
        }
        
        if ( s1.size() != s2.size() ){
            return false;
        }
        
        if ( s1 == s2 ) {
            return true;
        }
        
        // append s2 onto itself, and find s1 within s2
        // then invoke is_substring after ignoring s1 within s2
        // and appending the end of what is left of s2 onto the beginning
        // of what is left of s2
        s2 += s2;
        
        //
        // s1.size() is 11
        //
        // s1 = "waterbottle"
        // s2 = "erbottlewaterbottlewat"
        //       0123456789012345678901
        //       erbottle           wat
        //
        
        // 8
        int found_index = (int)s2.find(s1);
        if (found_index == std::string::npos ) {
            return false;
        }
        
        // 8 + 11 = 19
        int next_index = found_index + (int)s1.size();;
        
        // check substring from next_index till the end of the string
        // and the beginning of the string till the found index
        string wrap_around = s2.substr(next_index) + s2.substr(0, found_index);
        
        return is_substring(s1, wrap_around);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    string test1;
    string test2;
    
    
    test1 = "waterbottle";
    test2 = "erbottlewat";
    cout << "is_rotation(" << test1 << "," << test2 << "):" << solution.is_rotation(test1, test2) << endl;
    
    
    return 0;
}
