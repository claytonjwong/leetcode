/*
 
 139. Word Break
 
 https://leetcode.com/problems/word-break/description/
 
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
 
 For example, given
 s = "leetcode",
 dict = ["leet", "code"].
 
 Return true because "leetcode" can be segmented as "leet code".
 
 */

/*
 
 rec pseudo:
 
 change the dic vector into a set, pass that into a helper function
 
 check the string from L->R, using a helper function with beg/end index which start
 at position beg=0 and end=beg+1.
 
 Iterative backtracking:
 
 For each s[beg:end++)
 
 Recursive constraint:
 
 Check if there is a match in the set, if so, then recursively invoke this helper function
 with new beg index ( old end )
 
 Base case:
 
 if beg eq s.sz --> return true
 
 return false after iterative backtracking for-loop exits ( this means there is no match in the set )
 
 
 dp pseudo:
 
 let dp[i]=true denote that there is a way to use the dic words to construct the string s[0:i)
 build up strings from L->R, if a string can be built from [i,j), then set dp[j]=true,
 initially set dp[0]=true.  This means that yes we can always construct an empty string "".
 
 */

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

class SolutionREC {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> d(wordDict.begin(),wordDict.end());
        return helper(s,d,0);
    }
private:
    unordered_map<int,bool> memo{};
    bool helper(const string& s, set<string>& d, int beg){
        if (beg==s.size()) return memo[beg]=true;
        if (memo.find(beg)!=memo.end()) return memo[beg];
        bool res=false;
        for (int end=beg+1; end<=s.size(); ++end)
            if (d.find(s.substr(beg,end-beg))!=d.end()) res|=helper(s,d,end);
        return memo[beg]=res;
    }
};

class SolutionDP {
public:
    bool wordBreak(string s, vector<string>& d) {
        int m=(int)s.size();
        set<string> x(d.begin(),d.end());
        vector<bool> dp(m+1,false);
        dp[0]=true;
        for (int i=0; i<m; ++i)
            for (int len=1; i+len<=m; ++len)
                if (dp[i] && x.find(s.substr(i,len))!=x.end()) dp[i+len]=true;
        return dp[m];
    }
};

int main(int argc, const char * argv[]) {
    
    SolutionREC r;
    SolutionDP d;
    string str="leetcode";
    vector<string> dic{ "leet", "code" };
    cout << r.wordBreak(str,dic) << endl;
    cout << d.wordBreak(str,dic) << endl;
    
    return 0;
}



