/*
 
 Implement a method to perform basic string compresion using the counts of repeated characters.  For exmaple, the string aabcccccaaa would become a2b1c5a3.  If the "compressed" string would not become smaller than the original string, your method should return the original string.  You can assume that string has only uppercase and lowercase letters (a-z).
 
 */

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string compress(string s){
        string result = "";
        
        // go character by character, and compare curr to prev char
        auto prev = '\0';
        int count = 1;
        for (auto curr : s ){
            if (prev != '\0' ){
                if ( curr == prev ) {
                    count++;
                } else  {
                    result += prev + to_string(count);
                    count = 1;
                }
            }
            prev = curr;
        }
        result += prev + to_string(count);
        
        // result should be smaller than s if it is "compressed"
        if ( result.size() > s.size() ){
            return s;
        } else {
            return result;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    string test;
    cout << "compress(" << test << "): " << solution.compress(test) << endl;
    
    test = "";
    cout << "compress(" << test << "): " << solution.compress(test) << endl;

    test = "aabcccccaaa";
    cout << "compress(" << test << "): " << solution.compress(test) << endl;

    
    return 0;
}


