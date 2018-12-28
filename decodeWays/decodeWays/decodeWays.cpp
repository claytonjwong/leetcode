/*
 
 91. Decode Ways
 
 https://leetcode.com/problems/decode-ways/description/
 
 A message containing letters from A-Z is being encoded to numbers using the following mapping:
 
 'A' -> 1
 'B' -> 2
 ...
 'Z' -> 26
 Given an encoded message containing digits, determine the total number of ways to decode it.
 
 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 
 The number of ways decoding "12" is 2.
 
 */


#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


// AC
class Solution3 {
public:
    int numDecodings(string s) {
        unordered_map<int,int> m;
        return s.empty() ? 0 : go(m,s,(int)s.size(),0);
    }
private:
    int go(unordered_map<int,int>& m, const string& s, const int& n, int i){
        if (i==n) return m[i]=1;
        if (m.count(i)) return m[i];
        int cnt=0;
        int one=stoi(s.substr(i,1));
        if (1<=one&&one<=9)
            cnt+=go(m,s,n,i+1);
        if (n-i >= 2){
            int two=stoi(s.substr(i,2));
            if (10<=two&&two<=26)
                cnt+=go(m,s,n,i+2);
        }
        return m[i]=cnt;
    }
};

// AC
class Solution2 {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.size()==1 && stoi(s)!=0) return 1;
        int n=(int)s.size();
        vector<int> dp(n+1,0);
        dp[0]=s[0]!='0' ? 1 : 0; // [1:9] are valid one-digit encoding
        dp[1]=s[1]!='0' ? dp[0] : 0;
        for (int i=2; i<=n; ++i){
            int one=stoi(s.substr(i-1,1)),two=stoi(s.substr(i-2,2));
            dp[i]+=(one!=0) ? dp[i-1] : 0;
            dp[i]+=(10<=two&&two<=26) ? dp[i-2] : 0; // [10:26] are valid two-digit encoding
        }
        return dp[n];
    }
};

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.size()==1 && stoi(s)!=0) return 1;
        int dn_minus_2=s[0]!='0' ? 1 : 0; // [1:9] are valid one-digit encoding
        int dn_minus_1=s[1]!='0' ? dn_minus_2 : 0;
        int dn=0;
        for (int i=2; i<=s.size(); ++i){
            int one=stoi(s.substr(i-1,1)),two=stoi(s.substr(i-2,2));
            dn=(one!=0) ? dn_minus_1 : 0;
            dn+=(10<=two&&two<=26) ? dn_minus_2 : 0; // [10:26] are valid two-digit encoding
            dn_minus_2=dn_minus_1;
            dn_minus_1=dn;
        }
        return dn;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    Solution2 s2;
    string str{"9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253"};
    //string str{"222"};
    cout << s.numDecodings(str) << endl;
    cout << s2.numDecodings(str) << endl;
    
    return 0;
}
