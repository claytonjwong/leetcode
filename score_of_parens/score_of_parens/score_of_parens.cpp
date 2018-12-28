/*
 
 856. Score of Parentheses
 
 Q: https://leetcode.com/problems/score-of-parentheses/description/
 A: https://leetcode.com/problems/score-of-parentheses/discuss/142807/Concise-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string A, int d=0, int s=0) {
        for (int i=0,N=(int)A.size(); i<N; ++i){
            d=(A[i]=='(') ? d+1 : d-1;
            if (A[i]==')' && A[i-1]=='(')
                s+=1<<d;
        }
        return s;
    }
};
                           

int main(int argc, const char * argv[]) {
    
    Solution s;
    cout << "1==" << s.scoreOfParentheses("()") << endl;
    cout << "2==" << s.scoreOfParentheses("(())") << endl;
    cout << "2==" << s.scoreOfParentheses("()()") << endl;
    cout << "6==" << s.scoreOfParentheses("(()(()))") << endl;
    cout << "3==" << s.scoreOfParentheses("(())()") << endl;
    cout << "8==" << s.scoreOfParentheses("(((())))") << endl;
    
    return 0;
}



