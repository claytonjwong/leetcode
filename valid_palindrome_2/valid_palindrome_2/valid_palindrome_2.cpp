/*
 
 680. Valid Palindrome II
 
 https://leetcode.com/contest/leetcode-weekly-contest-50/problems/valid-palindrome-ii/
 
 Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.
 
 Example 1:
 Input: "aba"
 Output: True
 Example 2:
 Input: "abca"
 Output: True
 Explanation: You could delete the character 'c'.
 Note:
 The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
 
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.size() < 2) { return true; }
        return helper(s, 0, (int)s.size()-1, 1);
    }
    bool helper(string& s, int beg, int end, int d){
        if (beg >= end) { return true; }
        if (s[beg] == s[end]) { return helper(s, ++beg, --end, d); }
        return ( d>0 ) && ( helper(s,beg+1,end,d-1) || helper(s,beg,end-1,d-1) );
    }
};



int main(int argc, const char * argv[]) {
    
    Solution solution;
    while(true){
        string s;
        cout << "s: ";
        cin >> s;
        cout << solution.validPalindrome(s) << endl;
    }
    
    
    
    
    return 0;
}




