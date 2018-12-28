/*
 
 678. Valid Parenthesis String
 
 https://leetcode.com/contest/leetcode-weekly-contest-50/problems/valid-parenthesis-string/
 
 Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
 
 Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 Any right parenthesis ')' must have a corresponding left parenthesis '('.
 Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 An empty string is also valid.
 
 Example 1:
 Input: "()"
 Output: True
 
 Example 2:
 Input: "(*)"
 Output: True
 
 Example 3:
 Input: "(*))"
 Output: True
 
 Note:
 The string size will be in the range [1, 100].
 
 
 Solution: https://discuss.leetcode.com/topic/103948/java-12-lines-solution-backtracking/10
 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution{
public:
    bool checkValidString(string s){
        return helper(s, 0, 0);
    }
    
    bool helper(const string& s, int index, int open){
        if (index==s.size()) { return open==0; }
        if (s[index]=='('){
            ++open;
        } else if (s[index]==')'){
            --open;
            if (open<0){return false;}
        } else {
            return helper(s,index+1,open+1) || helper(s,index+1,open-1) || helper(s,index+1,open);
        }
        return helper(s,index+1,open);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    while(true){
        string s;
        cout << "s: ";
        cin >> s;
        cout << solution.checkValidString(s) << endl;
    }
    
    
    
    return 0;
}






