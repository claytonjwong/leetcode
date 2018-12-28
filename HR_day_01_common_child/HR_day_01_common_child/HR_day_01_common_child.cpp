/*
 
 Common Child
 
 https://www.hackerrank.com/challenges/common-child
 
 http://www.geeksforgeeks.org/dynamic-programming-set-4-longest-common-subsequence/
 
 
 Given two strings  and  of equal length, what's the longest string () that can be constructed such that it is a child of both?
 
 A string  is said to be a child of a string  if  can be formed by deleting 0 or more characters from .
 
 For example, ABCD and ABDC has two children with maximum length 3, ABC and ABD. Note that we will not consider ABCD as a common child because C doesn't occur before D in the second string.
 
 Input format
 
 Two strings,  and , with a newline separating them.
 
 Constraints
 
 All characters are upper cased and lie between ASCII values 65-90. The maximum length of the strings is 5000.
 
 Output format
 
 Length of string .
 
 Sample Input #0
 
 HARRY
 SALLY
 Sample Output #0
 
 2
 The longest possible subset of characters that is possible by deleting zero or more characters from HARRY and SALLY is AY, whose length is 2.
 
 Sample Input #1
 
 AA
 BB
 Sample Output #1
 
 0
 AA and BB has no characters in common and hence the output is 0.
 
 Sample Input #2
 
 SHINCHAN
 NOHARAAA
 Sample Output #2
 
 3
 The largest set of characters, in order, between SHINCHAN and NOHARAAA is NHA.
 
 Sample Input #3
 
 ABCDEF
 FBDAMN
 Sample Output #3
 
 2
 BD is the longest child of these strings.
 */

#include <iostream>


using namespace std;

class Solution{
public:
    static int LongestCommonSubsequence(string a, string b){
        
        /*
         
         check the last character of each string,
         if they are equal, then add one onto the result
         if they are NOT equal, then recursively check
         which subsequence is larger,
             the subsequence with a truncated by one
             OR
             the subsequence with b truncated by one
         
         
         */
        
        if (a.size() == 0 || b.size() == 0){
            return 0;
        }
        if (a[a.size()-1] == b[b.size()-1]){
            return 1 + Solution::LongestCommonSubsequence(
                a.substr(0,a.size()-1),
                b.substr(0,b.size()-1));
                                                          
        } else {
            return max (Solution::LongestCommonSubsequence(a.substr(0,a.size()-1), b),
                        Solution::LongestCommonSubsequence(b.substr(0,b.size()-1), a));
        }
        
    }
};

int main(int argc, const char * argv[]) {

    string a,b;
    cin >> a;
    cin >> b;
    
    cout << Solution::LongestCommonSubsequence(a, b) << endl;
    
    
    
    return 0;
}




