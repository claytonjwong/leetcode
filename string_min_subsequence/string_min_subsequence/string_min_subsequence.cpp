/*
 
 727. Minimum Window Subsequence
 
 https://leetcode.com/contest/weekly-contest-58/problems/minimum-window-subsequence/
 
 Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
 
 If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.
 
 Example 1:
 Input:
 S = "abcdebdde", T = "bde"
 Output: "bcde"
 Explanation:
 "bcde" is the answer because it occurs before "bdde" which has the same length.
 "deb" is not a smaller window because the elements of T in the window must occur in order.
 Note:
 
 All the strings in the input will only contain lowercase letters.
 The length of S will be in the range [1, 20000].
 The length of T will be in the range [1, 100].
 
 "jmeqksfrsdcmsiwvaovztaqenprpvnbstl"
 "m"
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class SolutionREC {
public:
    string minWindow(string s, string t){
        map<int,int> m{};
        helper(s,t,0,s.size()-1,m);
        auto res=*min_element(m.begin(),m.end());
        int len=res.first, idx=res.second;
        return s.substr(idx,len);
    }
    void helper(string s, string t, int beg, int end, map<int,int>& m){
        if (end-beg<t.size()) return;
        auto res=found(s,t,beg,end);
        if (res.first==-1) return;
        if (m.find(res.first)==m.end()){
            m[res.first]=res.second;
        } else {
            if (res.second < m[res.first])
                m[res.first]=res.second;
        }
        helper(s,t,beg+1,end,m);
        helper(s,t,beg,end-1,m);
    }
    pair<int,int> found(string s, string t, int beg, int end){
        int j=0,idx=0;
        for (int i=beg,j=0; i<=end; ++i){
            if (s[i]==t[j]){
                if (j==0) idx=i;
                ++j;
            }
            if (j==t.size())
                return (pair<int,int>)make_pair(i-idx+1,idx);
        }
        return pair<int,int>(make_pair(-1,-1));
    }
};

void printDP(vector<vector<int>>& dp){
    for (auto &&r: dp){
        for (auto &&c: r){
            if (c==-1) cout << "X";
            else cout << c;
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    string minWindow(string S, string T) {
        int m=(int)S.size(), n=(int)T.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
            if (S[i] == T[0]) dp[0][i] = i;
        
        printDP(dp);
        
        for (int j = 1; j < n; j++) {
            int k = -1;
            for (int i = 0; i < m; i++) {
                if (k != -1 && S[i] == T[j]) dp[j][i] = k;
                if (dp[j-1][i] != -1) k = dp[j-1][i];
            }
            
            printDP(dp);
            
        }
        int st = -1, len = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (dp[n-1][i] != -1 && i-dp[n-1][i]+1 < len) {
                st = dp[n-1][i];
                len = i-dp[n-1][i]+1;
            }
        }
        return st == -1? "":S.substr(st, len);
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution dp;
    cout << dp.minWindow("abcabc", "aba") << endl;
    /*
    Solution rec;
    while(true){
        string s,t;
        cout << "s: ";
        cin >> s;
        cout << "t: ";
        cin >> t;
        cout << rec.minWindow(s,t) << endl;
    }
     */
/*
        if (res.first>=0)
            cout << "Found!  Len=" << res.first << " Idx=" << res.second << endl;
        else
            cout << "Not Found!" << endl;
    }
*/
    return 0;
}
