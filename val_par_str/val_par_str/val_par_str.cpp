/*
 
 Q: https://leetcode.com/problems/valid-parenthesis-string/
 A: https://leetcode.com/problems/valid-parenthesis-string/discuss/128527/Short-and-Simple-C++-(-EASY-to-understand-)
 
 */



#include <iostream>

using namespace std;


class Solution{
public:
    bool checkValidString(string s){
        return go(s);
    }
    
    bool go(const string& s, int i=0, int open=0){
        if (open < 0)
            return false;

        if (i==s.size())
            return open==0;
        
        if (s[i]=='(')
            ++open;
        
        else if (s[i]==')')
            --open;
        
        else
            return go(s,i+1,open+1) || go(s,i+1,open-1) || go(s,i+1,open);
        
        return go(s,i+1,open);
    }
};
 



int main(int argc, const char * argv[]) {
    
    Solution s;
    cout << s.checkValidString(")(") << endl;

    return 0;
}
