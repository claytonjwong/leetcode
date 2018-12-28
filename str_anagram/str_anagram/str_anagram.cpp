/*
 
 Given two strings write a method to decide if one is an anagram of the other
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    bool is_anagram(string s1, string s2) {
        
        unordered_map<char,int> alpha;

        // sanity checks
        if ( s1.size() != s2.size() ) {
            return false;
        }
        
        // initially set all character counts to 0
        for (int i=0; i < 26; i++) {
            alpha['a' + i] = 0;
        }
        
        // add 1 for each letter found in s1
        for (auto ch : s1 ) {
            ch = tolower(ch);
            alpha[ch]++;
        }

        // sub 1 for each letter found in s2
        for (auto ch : s2 ) {
            ch = tolower(ch);
            alpha[ch]--;
        }

        // the count each letter should be 0,
        // otherwise s1/s2 are NOT anagrams
        for (auto entry : alpha ) {
            if (entry.second != 0) {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    cout << "1 == " << solution.is_anagram("", "") << endl;
    cout << "1 == " << solution.is_anagram("ab", "ba") << endl;
    cout << "1 == " << solution.is_anagram("BA", "AB") << endl;
    cout << "1 == " << solution.is_anagram("abba", "baab") << endl;
    cout << "0 == " << solution.is_anagram("abbaa", "baabb") << endl;
    cout << "0 == " << solution.is_anagram("a", "b") << endl;
    
    
    
    return 0;
}
