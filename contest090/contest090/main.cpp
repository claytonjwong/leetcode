/*
 
 Rank           Name            Score   Finish Time     Q1 (4)      Q2 (5)      Q3 (6)    Q4 (9)
 1009 / 4410    claytonjwong    9       1:26:03         0:15:02     1:16:03  2
 
 Q1: https://leetcode.com/problems/buddy-strings/description/
 A1: https://leetcode.com/problems/buddy-strings/discuss/141769/Straightforward-C++-with-explanation
 
 Q2: https://leetcode.com/problems/score-of-parentheses/description/
 A2: https://leetcode.com/problems/score-of-parentheses/discuss/141792/C++-Regex
 
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <regex>


using namespace std;

/*
 
 trivial size cases:
 
 if size of A is less than 2, then there are not two chars to swap, return false
 if the size of A is not equal to the size of B, then return false
 
 other cases: either A equals B or A does NOT equal B
 
 if A==B, then return true if and only if A contains a ```dup```licate char which can be swapped while allowing A to remain the same
 
 if A!=B, then let i be the index of the first char different between A and B scanning from the left and let j be the index of the first char different between A and B scanning from the right.  Swap the chars of A in index i and index j and return true if this updated A is equal to B, and return false otherwise.
 */
/*
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() < 2 || A.size()!=B.size()) return false;
        unordered_map<char,int> m;
        bool dup=false; for (auto& c: A) if (++m[c]>1) dup=true;
        if (A==B) return dup;
        int i=0,N=(int)A.size(),j=N-1;
        while (i<N-1 && A[i]==B[i]) ++i;
        while (j>0   && A[j]==B[j]) --j;
        swap(A[i],A[j]);
        return A==B;
    }
    
};

int main(int argc, const char * argv[]) {
    
    
    Solution s;
    cout << s.buddyStrings("", "aa") << endl;
    cout << s.buddyStrings("aaa", "aa") << endl << endl;
    
    cout << s.buddyStrings("aa", "aa") << endl;
    cout << s.buddyStrings("ab", "ab") << endl << endl;
    
    cout << s.buddyStrings("ab", "ba") << endl;
    
    cout << s.buddyStrings("aaaaaaabc", "aaaaaaacb") << endl;
    
    return 0;
}
*/

using RE=regex;
class Solution {
public:
    int scoreOfParentheses(string S, RE add=RE("(\\d+)\\s+(\\d+)"), RE dub=RE("\\(\\s*(\\d*)\\s*\\)"), smatch m=smatch(), bool found=true, int ans=0) {
        for (int i=(int)S.find("()"); i!=string::npos; i=(int)S.find("()")) S.replace(i,2," 1 ");
        while (found && !(found=false)){
            while (regex_search(S,m,add) && (found=true))
                S.replace(S.find(m[0]),string(m[0]).size(),to_string(stoi(m[1])+stoi(m[2])));
            while (regex_search(S,m,dub) && (found=true))
                S.replace(S.find(m[0]),string(m[0]).size()," "+to_string(2*stoi(m[1]))+" ");
        }
        return stoi(S);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    
    
    cout << s.scoreOfParentheses("()") << endl;
    cout << s.scoreOfParentheses("(())") << endl;
    cout << s.scoreOfParentheses("()()") << endl;
    cout << s.scoreOfParentheses("(()(()))") << endl;
    cout << s.scoreOfParentheses("()(())") << endl;
    cout << s.scoreOfParentheses("(())(())") << endl;
}




