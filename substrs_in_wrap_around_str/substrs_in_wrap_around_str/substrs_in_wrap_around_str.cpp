/*
 
 467. Unique Substrings in Wraparound String
 
 Q: https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 A: https://leetcode.com/problems/unique-substrings-in-wraparound-string/discuss/136292/straightforward-c-with-explanation
 
 */


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
using VI=vector<int>;
class Solution {
public:
    int findSubstringInWraproundString(string s, VI v=VI(26,0)) {
        for (int i=0,N=(int)s.size(); i<N; ++i){
            int k=1; for (;i+k<N && next(s[i+k-1])==s[i+k]; ++k); // increment k
            int bucket=s[i]-'a';
            v[bucket]=max(v[bucket],k);
        }
        return accumulate(v.begin(),v.end(),0);
    }
private:
    const char next(const char c) const { return c=='z' ? 'a' : c+1; }
};
*/

/*
using VI=vector<int>;
class Solution {
public:
    int findSubstringInWraproundString(string s, VI v=VI(26,0)) {
        if (s.empty()) return 0;
        vector<int> dp(s.size());
        dp[0]=1;
        v[s[0]-'a']=1;
        for (int i=1,N=(int)s.size(); i<N; ++i){
            char c=next(s[i-1]);
            if (c==s[i])
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
            int bucket=s[i]-'a';
            v[bucket]=max(v[bucket],dp[i]);
        }
        return accumulate(v.begin(),v.end(),0);
    }
private:
    const char next(const char c) const { return c=='z' ? 'a' : c+1; }
};
*/

/*
using VI=vector<int>;
class Solution {
public:
    int findSubstringInWraproundString(string s, VI v=VI(26,0)) {
        for (int i=0,N=(int)s.size(),len=1; i<N; ++i){
            char c=i>0 ? next(s[i-1]) : '\0';
            if (c==s[i])
                ++len;
            else
                len=1;
            int bucket=s[i]-'a';
            v[bucket]=max(v[bucket],len);
        }
        return accumulate(v.begin(),v.end(),0);
    }
private:
    const char next(const char c) const { return c=='z' ? 'a' : c+1; }
};
*/

using VI=vector<int>;
class Solution {
public:
    int findSubstringInWraproundString(string s, VI v=VI(26,0)) {
        for (int i=0,N=(int)s.size(),len=1; i<N; ++i){
            len=(i>0 && next(s[i-1])==s[i]) ? len+1 : 1;
            v[s[i]-'a']=max(v[s[i]-'a'],len);
        }
        return accumulate(v.begin(),v.end(),0);
    }
private:
    const char next(const char c) const { return c=='z' ? 'a' : c+1; }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    //cout << "1==" << s.findSubstringInWraproundString("a") << endl;
    cout << "3==" << s.findSubstringInWraproundString("ace") << endl;
    cout << "2==" << s.findSubstringInWraproundString("cac") << endl;
    cout << "6==" << s.findSubstringInWraproundString("zab") << endl;
    cout << "9==" << s.findSubstringInWraproundString("zabde") << endl;
    
    return 0;
}
