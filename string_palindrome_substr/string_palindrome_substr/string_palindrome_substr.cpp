/*
 
 647. Palindromic Substrings
 
 https://leetcode.com/contest/leetcode-weekly-contest-42/problems/palindromic-substrings/
 
 Given a string, your task is to count how many palindromic substrings in this string.
 
 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.
 
 Example 1:
 Input: "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 Example 2:
 Input: "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 Note:
 The input string length won't exceed 1000.
 
 
 */



#include <iostream>
#include <string>

using namespace std;


class Solution{
public:
    int countSubstrings(string s){
        
        // iterate through each letter, count the letter itself as a palindrome
        // then try to find even sized palindromes surrounding this letter
        // then try to find odd sized palindromes surrounding this letter
        int cnt=0;
        
        for (string::iterator itr=s.begin(); itr < s.end(); itr++){
            
            cnt++; // count this char itself as a palindrome
            
            // find even sized palindromes
            string::iterator left = itr; left++; // left will initially be itr
            string::iterator right = itr;        // right will initially be itr+1
            while (left != s.begin() && right < s.end()){
                left--;
                right++;
                // even palindrome found, increment count, iterate outwards
                if (*left == *right){
                    cnt++;
                } else {
                    break; // not a palindrome, no need to further iterate outwards
                }
            }
            
            // find odd sized palindromes
            left = itr;
            right = itr;
            while ( left != s.begin() && right < s.end()){
                left--;
                right++;
                if (*left == *right){
                    cnt++;
                } else {
                    break;
                }
            }
            
        }
        
        return cnt;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    cout << "3 == " << solution.countSubstrings("abc") << endl;
    cout << "6 == " << solution.countSubstrings("aaa") << endl;
    cout << "9 == " << solution.countSubstrings("leetcode") << endl;
    
    return 0;
}




