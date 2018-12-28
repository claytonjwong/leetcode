/*
 
 408. Valid Word Abbreviation
 
 https://leetcode.com/problems/valid-word-abbreviation/description/
 
 Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
 
 A string such as "word" contains only the following valid abbreviations:
 
 ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
 Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
 
 Note:
 Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
 
 Example 1:
 Given s = "internationalization", abbr = "i12iz4n":
 
 Return true.
 Example 2:
 Given s = "apple", abbr = "a2e":
 
 Return false.
 
 */



#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i=0, j=0;
        while (i < word.size() && j < abbr.size()){
            if (isdigit(abbr[j])){
                int num=abbr[j]-'0';
                if (num==0){ return false; }
                while (j+1 < abbr.size() && isdigit(abbr[j+1])) {
                    num*=10+abbr[++j]-'0';
                }
                i+=num; j++;
            }
            else if (word[i++] != abbr[j++]) { return false; }
        }
        return i==word.size() && j==abbr.size();
    }
};

int main(int argc, const char * argv[]) {

    
    
    
    Solution solution;
    string word{};
    cout << "word: ";
    cin >> word;
    while (true){
        string abbr{};
        cout << "abbr: ";
        cin >> abbr;
        cout << solution.validWordAbbreviation(word, abbr) << endl << endl;
    }
    
    return 0;
}












