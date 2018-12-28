/*
 
 Given a string wrote a funtion to check if it is a permutation of a palindrome.
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    bool is_pp(string s){
        
        // sanity checks
        if ( s.empty() ) {
            return false;
        }
        
        // track the count of each char of s only contains letters and spaces
        int flip=0;
        for ( auto ch : s ){

            if (!isspace(ch)){
                flip ^= 1 << ('a' - tolower(ch));
            }
        }
        
        // characters with an even count will be flipped an even amount of times
        // only one character is allowed to be flipped an odd amount of times for odd len string
        // so see if there is just one bit set (i.e. flip is a power of 2)
        return flip == 0 || ( flip & (flip - 1) ) == 0; // odd len string, all bits except 1 should be 0
        
    }
};

int main(int argc, const char * argv[]) {

    Solution solution;

    string test;
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    test = "race car";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    test = "a man a plan a canal panama";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;

    
    test = "something else";
    cout << "is_pp(" << test << "): " << solution.is_pp(test) << endl;
    
    return 0;
}
