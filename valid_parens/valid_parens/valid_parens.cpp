/*
 
 20. Valid Parentheses
 
 https://leetcode.com/problems/valid-parentheses/#/description
 
 
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 
 */


#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack{};
        for (const auto& c : s){
            switch(c){
                case '(': stack.push(')'); break;
                case '{': stack.push('}'); break;
                case '[': stack.push(']'); break;
                default:
                    if (stack.empty() || c!=stack.top()) { return false; }
                    stack.pop();
                    break;
            }
        }
        return stack.empty() ? true : false;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solution;
    
    cout << "() == " << solution.isValid("()") << endl;
    
    cout << "] == " << solution.isValid("]") << endl;
    
    cout << "[ == " << solution.isValid("[") << endl;
    
    
    return 0;
}
