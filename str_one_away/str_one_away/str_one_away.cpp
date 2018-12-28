/*
 
 There are three types of edits that can be performed on trings: insert a character, remove a character, or replace a character.  Given two strings, write a funtion to check if they are one edit ( or zero edits ) away.
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool one_away(string s1, string s2){
        
        // sanity checks
        if (( s1.empty() and s2.size() <= 1 ) or ( s2.empty() and s1.size() <= 1 )){
            return true; // "" + "a" are one off and "" + "" are zero off
        }
        
        if ( abs ( (int)(s1.size() - s2.size()) ) > 1 ){
            return false; // size diff cannot be > 1
        }
        
        // ensure all chars are the same, with one exception
        bool exception_found = false;
        int i=0;
        int j=0;
        
        while ( i < s1.size() and j < s2.size() ){ // i from [0:s1.size)  j from [0:s2.size)
            
            if ( i == s1.size() or j == s2.size() ){
                // all chars match except for the very last char
                // we know this because we previously checked the size diff
                // between s1 and s2 cannot be > 1
                return true;
            }
            
            // check for equality exception
            if ( s1[i] != s2[j] ){
                
                if ( exception_found ) {
                    return false; // only one exception is allowed
                } else {
                    exception_found = true;
                }
                
                // see if the next char matches, if so, iterate past this execption
                if ( s1[i+1] == s2[j] ) {
                    i++; // "pale" + "ple" ==> iterate i forward
                         //   i        j
                    
                } else if ( s1[i] == s2[j+1] ) {
                    j++; // "ple" + "pale" ==> iterate j forward
                         //   i       j
                    
                } else if ( s1[i+1] == s2[j+1] ) {
                    i++; // "pale" + "bale" ==> iterate forward
                    j++; //  i        j
                    
                } else {
                    return false; // exception found and next char does NOT match
                }
                
            }
            
            i++;
            j++;
        }
        
        
        return true;
    }
    
};

int main(int argc, const char * argv[]) {
    
    string test1;
    string test2;
    Solution solution;
    
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;
    
    test1 = "pale";
    test2 = "ple";
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;

    test1 = "pales";
    test2 = "pale";
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;

    test1 = "pale";
    test2 = "bale";
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;

    test1 = "";
    test2 = "a";
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;

    test1 = "pale";
    test2 = "bake";
    cout << "one_away(" << test1 << "," << test2 << "): " << solution.one_away(test1, test2) << endl;

    
    return 0;
}
