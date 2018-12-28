/*
 
 Implement an algorithm to determine if a string has all unique characters
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    bool is_unique(string s) {
        
        unordered_map<char,int> alpha;
        
        for (int i=0; i < 26; i++) {
            alpha['a' + i] = 0;
        }
        
        for (auto ch : s ){
            
            ch = tolower(ch);
            
            if (alpha[ch] == 0) {
                alpha[ch] = 1;
            } else {
                return false;
            }
        }
        
        
        
        return true;
    }

};


int main(int argc, const char * argv[]) {
    
    
    Solution solution;
    cout << solution.is_unique("abcc") << endl;
    return 0;
}
