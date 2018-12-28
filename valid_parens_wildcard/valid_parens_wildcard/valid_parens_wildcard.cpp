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
 
 
 Solution: https://discuss.leetcode.com/topic/104298/c-count-open-parens-from-left-to-right-then-right-to-left
 
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution{
public:
    bool checkValidString(string s){
        return helper(s, '(', ')') && helper({s.rbegin(),s.rend()}, ')', '(');
    }
    
    bool helper(const string& s, const char& beg, const char& end){
        int open=0, wildcard=0;
        int i=0;
        for (auto& ch : s){
            if(ch==beg){++open;} else if(ch==end){--open;} else{++wildcard;}
            if(open < 0 && wildcard < -open){
                return false;
            }
        }
        return open <= wildcard ? true : false;
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
    
    //
    // false positive found for below input from left-to-right,
    // hack this solution by checking in reverse order (right-to-left) as well
    //
    
    //string s="(())((())()()(*)(*()(())())())()()((()())((()))(*";
    //cout << solution.checkValidString(s) << endl;

    //                                 (())((())()()(*)(*()(())())())()()((()())((()))(*
    //                                 0123456789012345678901234567890123456789012345678
    //                           open  121012321212122122323432321210
    //                           wild  0000000000000011122
 
    
    
    return 0;
}



